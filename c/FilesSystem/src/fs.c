#include <math.h>
#include "fs.h"
#include "disk.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#include <stdbool.h>

#define FS_MAGIC           0xf0f03410
#define INODES_PER_BLOCK   128
#define POINTERS_PER_INODE 5
#define POINTERS_PER_BLOCK 1024
//static int iBitMapBlock=0; // Number of the first BitMap block
//static int nBitMap; // How many blocks are allocated for bitMap

static char* BitMap = NULL;

struct fs_superblock {
	unsigned int magic;
	int nblocks;
	int ninodeblocks;
	int ninodes;
};

struct fs_inode {
	int isvalid;
	int size;
	int direct[POINTERS_PER_INODE];
	int indirect;
};

union fs_block {
	struct fs_superblock super;
	struct fs_inode inode[INODES_PER_BLOCK];
	int pointers[POINTERS_PER_BLOCK];
	char data[DISK_BLOCK_SIZE];
};

void printarr(int *arr, int size){
    for(int i=0; i<size; ++i)
        printf("%d,", arr[i]);
    printf("\n");
}

int fs_format()
{	
	
	if(BitMap){
		printf("ERROR - simplefs is already mounted, it's not possible to format\n");
		return 0;
	}
	union fs_block Sblock;
	disk_read(0,Sblock.data);
	if(Sblock.super.magic==FS_MAGIC){
		int confirm=0;
		while(!confirm){
			printf("ERROR - file system exists, are you sure you want to format? [y/n]\n");
			char s;
			scanf("%s",&s);
				switch(s)
				{
				case 'y':
					confirm=1;
					break;
				case 'n':
					return 0;
					break;
				default:
					break;
				}
		}
	}
	Sblock.super.magic= FS_MAGIC;
	Sblock.super.nblocks = disk_size();
	Sblock.super.ninodeblocks = ceil(Sblock.super.nblocks/10);
	Sblock.super.ninodes = Sblock.super.ninodeblocks*INODES_PER_BLOCK;
	disk_write(0,Sblock.data);
	union fs_block Iblock;
	for(int i=0;i<INODES_PER_BLOCK;++i){
		Iblock.inode[i].isvalid = 0;
		Iblock.inode[i].size = 0;
		Iblock.inode[i].indirect=0;
		for(int j=0;j<POINTERS_PER_INODE;++j)
			Iblock.inode[i].direct[j]= 0;
	}
	int i= 1;
	while (i<Sblock.super.ninodeblocks+1)
		disk_write(i++,Iblock.data);
	return 1;
}

void fs_debug()
{
	union fs_block Sblock;

	disk_read(0,Sblock.data);
	printf("superblock:\n");
	if(Sblock.super.magic!=FS_MAGIC){
		printf("\033[1;31mmagic number is invalid\033[0m\n");
		printf("closing emulated disk.\n");
		disk_close();
		exit(0);
	}
	printf("\tmagic number is valid\n");
	printf("\t%d blocks\n",Sblock.super.nblocks);
	printf("\t%d inode blocks\n",Sblock.super.ninodeblocks);
	printf("\t%d inodes\n",Sblock.super.ninodes);
	union fs_block Iblock;
	for(int i=1;i<=Sblock.super.ninodeblocks;++i){
		disk_read(i,Iblock.data);
		for(int j=0;j<INODES_PER_BLOCK;++j){
			if(!Iblock.inode[j].isvalid)
				continue;
			printf("\033[1;35minode %d:\n\033[0m",j+((i-1)*INODES_PER_BLOCK));
			printf("\tsize: %d bytes\n\tdirect blocks:",Iblock.inode[j].size);
			for(int k=0;k<POINTERS_PER_INODE;++k){
				if(Iblock.inode[j].direct[k])
					printf("\t%d",Iblock.inode[j].direct[k]);
			}
			if(Iblock.inode[j].indirect){
				printf("\n\tindirect block: %d\n",Iblock.inode[j].indirect);
				union fs_block Dblock;
				disk_read(Iblock.inode[j].indirect ,Dblock.data);
				printf("\tindirect data blocks: ");
				for(int k=0;k<POINTERS_PER_BLOCK;++k)
					if(Dblock.pointers[k])
						printf("\t%d",Dblock.pointers[k]);
					else
						break;
			}
		printf("\n");
		}
	}
}

int fs_mount()
{
	//union fs_block block;
	//iBitMapBlock= ceil(disk_size()/10)+1;
	/*printf("disksuze = %d\tPOINTERS_PER_BLOCK = %d\t%f\n",disk_size(), POINTERS_PER_BLOCK,(float) disk_size()/POINTERS_PER_BLOCK);
	float diskBlocks =(float) disk_size()/POINTERS_PER_BLOCK;
	printf("   %lf\n",diskBlocks);*/
	//nBitMap= 1+ceil(disk_size()/POINTERS_PER_BLOCK);
	//nBitMap = (disk_size()%POINTERS_PER_BLOCK==0)?disk_size()/POINTERS_PER_BLOCK : disk_size()/POINTERS_PER_BLOCK+1;
	//printf("nBitMap = %d\tiBitMapBlock = %d\n",nBitMap, iBitMapBlock);
	union fs_block Sblock;
	disk_read(0,Sblock.data);
	if(Sblock.super.magic!=FS_MAGIC){
		printf("ERROR - File system does not exist, use 'format'\n");
		return 0;
	}
	unmount();
	BitMap=(char*)calloc(disk_size(),sizeof(char));
	if(!BitMap)
		return 0;
	int i;
	for(i=0;i< Sblock.super.ninodeblocks+1 ;++i)
		BitMap[i]= 1; //marks all system blocks

	union fs_block Iblock;
	for(int i=1;i<=Sblock.super.ninodeblocks;++i){
		disk_read(i,Iblock.data);
		for(int j=0;j<INODES_PER_BLOCK;++j){
			if(!Iblock.inode[j].isvalid)
				continue;
			for(int k=0;k<POINTERS_PER_INODE;++k){
				if(Iblock.inode[j].direct[k])
					BitMap[Iblock.inode[j].direct[k]]=1;
			}
			if(Iblock.inode[j].indirect){
				BitMap[Iblock.inode[j].indirect]=1;
				union fs_block Dblock;
				disk_read(Iblock.inode[j].indirect ,Dblock.data);
				for(int k=0;k<POINTERS_PER_BLOCK;++k)
					if(Dblock.pointers[k])
						BitMap[Dblock.pointers[k]]=1;
			}
		}
	}
	for(int i=0;i<disk_size();++i)
		printf("bitmap[%d]= %d\n ",i,BitMap[i]);
	return 1;
}

void unmount()
{
	if(BitMap)
		free(BitMap);
}

int fs_create()
{
	int InodeIndex = getFreeInode();
	printf("%d\n",InodeIndex );
	if(InodeIndex==-1)
		return -1;
	
	union fs_block Iblock;
	disk_read((InodeIndex/INODES_PER_BLOCK)+1,Iblock.data);
	if(Iblock.inode[InodeIndex%INODES_PER_BLOCK].isvalid){
		printf("ERROR - Incompatibility between the system and the bitmap\n\033[1;41mThe system closes\n\033[0m");
		disk_close();
	}

	Iblock.inode[InodeIndex%POINTERS_PER_BLOCK].size = 0;
	Iblock.inode[InodeIndex%POINTERS_PER_BLOCK].indirect=0;
	for(int j=0;j<POINTERS_PER_INODE;++j)
		Iblock.inode[InodeIndex%POINTERS_PER_BLOCK].direct[j]= 0;
	disk_write(1+(InodeIndex/POINTERS_PER_BLOCK),Iblock.data);
	return InodeIndex;
}

int getFreeInode(){
	union fs_block Iblock;
	for(int i=1;i<=ceil(disk_size()/10)+1;++i){
		disk_read(i,Iblock.data);
		for(int j=0;j<INODES_PER_BLOCK;++j){
			if(!Iblock.inode[j].isvalid)
				return j+((i-1)*INODES_PER_BLOCK);
		}
	}
	printf("ERROR - No free inode exists\n");
	return -1;
}

//Returns a free block number ,returns -1 if none exists 
int getFreeBlock()
{
	if(!BitMap){
		printf("The file system has not yet been mounted\
		\n\033[1;32mPlease use\033[0m:\
		\n\t'mount'\n");
		return -1;
	}
	for(int i=ceil(disk_size()/10)+1 ;i<disk_size() ;++i)
		if(!BitMap[i]){
			BitMap[i]=1;
			return i;
		}
	
	printf("ERROR - No free block exists\n");
	return -1;
}

int fs_delete( int inumber )
{
	if(inumber>(ceil(disk_size()/10)*INODES_PER_BLOCK)){
		printf("\033[2:34minvalid inumber\033[0m\n");
		return 0;
	}
	union fs_block Iblock;
	disk_read((inumber/INODES_PER_BLOCK)+1,Iblock.data);
	if(!Iblock.inode[inumber].isvalid){
		printf("inonde has already been deleted\n");//???
		return 1;
	}
	Iblock.inode[inumber].isvalid=0;
	Iblock.inode[inumber].size=0;
	for(int i=0;i<POINTERS_PER_INODE;++i){
		BitMap[Iblock.inode[inumber].direct[i]]=0;
		Iblock.inode[inumber].direct[i]=0;
	}
	if(Iblock.inode[inumber].indirect){
		union fs_block Dblock;
		disk_read(Iblock.inode[inumber].indirect,Dblock.data);
		for(int i=0;i<POINTERS_PER_BLOCK;++i)
			BitMap[Dblock.pointers[i]]=0;
	}
	BitMap[Iblock.inode[inumber].indirect]=0;
	disk_write((inumber/INODES_PER_BLOCK)+1,Iblock.data);
	return 1;
}

int fs_getsize( int inumber )
{	
	if(inumber>(ceil(disk_size()/10)*INODES_PER_BLOCK)){
		printf("\033[2;34minvalid inumber\033[0m\n");
		return -1;
	}
	union fs_block Iblock;
	disk_read((inumber/INODES_PER_BLOCK)+1,Iblock.data);
	return (Iblock.inode[inumber%INODES_PER_BLOCK].isvalid)? Iblock.inode[inumber%INODES_PER_BLOCK].size : -1;
}
//Returns the number of the block where the inode is located
int getBlockInodeNum(int inumber ){
	return (inumber/INODES_PER_BLOCK)+1;
}

//Returns the inode number inside the block
int getInodeIndex(int inumber ){
	return inumber%INODES_PER_BLOCK;
}

int fs_read( int inumber, char *data, int length, int offset)
{	
	sanity_check(inumber,data);
	union fs_block Iblock;
	disk_read(getBlockInodeNum(inumber),Iblock.data);
	if(!Iblock.inode[getInodeIndex(inumber)].isvalid)	//Checking whether the inode is valid
		return -1;
	
	int offset2 =(offset%DISK_BLOCK_SIZE);//index of block
	int iterations=DISK_BLOCK_SIZE-(offset%DISK_BLOCK_SIZE);
	int count=0;//How many times a copy was made

	for(int i=0;i<length/DISK_BLOCK_SIZE && offset+count< fs_getsize(inumber);++i){
		printf(" offset2 =%d  ; iterations = %d , count= %d\n"\
	, offset2,iterations,count);
		int dataBlockNum = getBlockNumByte(inumber,offset+count);
		printf("\033[1;35m - dataBlockNum = %d\033[0m\n",dataBlockNum );
		copy('r',dataBlockNum ,data, iterations, count ,offset2);
		count+=iterations;
		iterations= ((fs_getsize(inumber)-count-offset)> DISK_BLOCK_SIZE)?\
		DISK_BLOCK_SIZE :fs_getsize(inumber)-count-offset;
		offset2=0;
	}
	return count;
}

//Returns the block number, given a number of bytes
int getBlockNumByte(int inumber , int offset){
	union fs_block Iblock;
	disk_read(getBlockInodeNum(inumber),Iblock.data);
	if(offset<DISK_BLOCK_SIZE*POINTERS_PER_INODE){
		return (Iblock.inode[getInodeIndex(inumber)].direct[offset/DISK_BLOCK_SIZE])?\
		Iblock.inode[getInodeIndex(inumber)].direct[offset/DISK_BLOCK_SIZE]:-1;
	}
	else{
		union fs_block IDblock;
			disk_read(Iblock.inode[getInodeIndex(inumber)].indirect ,IDblock.data);
			return (IDblock.pointers[(offset-(DISK_BLOCK_SIZE*POINTERS_PER_INODE))/DISK_BLOCK_SIZE])?\
			IDblock.pointers[(offset-(DISK_BLOCK_SIZE*POINTERS_PER_INODE))/DISK_BLOCK_SIZE]:-1;
	}
}

//Set the block number in inode
void setBlockNumByte(int inumber , int offset , int nBlock){
	union fs_block Iblock;
	disk_read(getBlockInodeNum(inumber),Iblock.data);
	if(offset<DISK_BLOCK_SIZE*POINTERS_PER_INODE && !Iblock.inode[getInodeIndex(inumber)].direct[offset/DISK_BLOCK_SIZE]){
		Iblock.inode[getInodeIndex(inumber)].direct[offset/DISK_BLOCK_SIZE] = nBlock;
		disk_write(getBlockInodeNum(inumber),Iblock.data);
		return;
	}
	else if (offset>=DISK_BLOCK_SIZE*POINTERS_PER_INODE){
		union fs_block IDblock;
			disk_read(Iblock.inode[getInodeIndex(inumber)].indirect ,IDblock.data);
			if(!IDblock.pointers[(offset-(DISK_BLOCK_SIZE*POINTERS_PER_INODE))/DISK_BLOCK_SIZE]){
				IDblock.pointers[(offset-(DISK_BLOCK_SIZE*POINTERS_PER_INODE))/DISK_BLOCK_SIZE]=nBlock;
				disk_write(getBlockInodeNum(inumber),Iblock.data);
				return;
			}
	}
	printf("ERORR = setBlockNumByte");
	exit(0);
}

void copy( int permission, int nBlock , char *data, int iterations, int offset1 , int offset2){
	if(permission=='r'){
		union fs_block Dblock;
		disk_read(nBlock ,Dblock.data);
		for(int j=0;j< iterations;++j){
			data[j+offset1] = Dblock.data[j+offset2];
		}
	}
	else if(permission=='w'){
			union fs_block Dblock;
			for(int j=0;j< iterations;++j){
				Dblock.data[j+offset2]= data[j+offset1] ;
			}
			disk_write(nBlock ,Dblock.data);
	}
	else
		exit(0);
}

int fs_write( int inumber, const char *data, int length, int offset )
{
	if(inumber>(ceil(disk_size()/10)*INODES_PER_BLOCK)){
		printf("\033[2;34minvalid inumber\033[0m\n");
		return -1;
	}
	union fs_block Iblock;
	disk_read(getBlockInodeNum(inumber) ,Iblock.data);
	if(!Iblock.inode[getInodeIndex(inumber)].isvalid){ // || Iblock.inode[getInodeIndex(inumber)].size!=offset){
		printf("ERORR - invalid inumber \n Please use 'create'\n" );
		return -1;
	}

	if(!Iblock.inode[getInodeIndex(inumber)].size){
		Iblock.inode[getInodeIndex(inumber)].indirect=0;
		for(int j=0;j<POINTERS_PER_INODE;++j)
			Iblock.inode[getInodeIndex(inumber)].direct[j]= 0;
		disk_write(getBlockInodeNum(inumber) ,Iblock.data);//???
	}

	int offset2 =(offset%DISK_BLOCK_SIZE);//index of block
	int iterations= (length%DISK_BLOCK_SIZE);
	int count=0;//How many times a copy was made

	if(!BitMap && !fs_mount())
		return -1;

	for(int i=0;i<ceil(length/DISK_BLOCK_SIZE);++i){
		int nFreeBlock = getFreeBlock();
		if(nFreeBlock<0){
			fs_delete(inumber);
			return -(length+count);
		}
		copy('w', nFreeBlock ,data, iterations,count,offset+count);
		setBlockNumByte(inumber,offset+count,nFreeBlock);
		Iblock.inode[getInodeIndex(inumber)].size+=iterations;
		count+=iterations;
		iterations=DISK_BLOCK_SIZE-(offset%DISK_BLOCK_SIZE);//??
	}
	disk_write(getBlockInodeNum(inumber),Iblock.data);
	
	return 0;
}