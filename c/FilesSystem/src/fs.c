#include "fs.h"
#include "disk.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#define FS_MAGIC           0xf0f03410
#define INODES_PER_BLOCK   128
#define POINTERS_PER_INODE 5
#define POINTERS_PER_BLOCK 1024

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

int fs_format()
{
	return 0;
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
			printf("\033[1;35minode %d:\n\033[0m",j);
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
	return 0;
}

int fs_create()
{
	return -1;
}

int fs_delete( int inumber )
{
	return 0;
}

int fs_getsize( int inumber )
{
	return -1;
}

int fs_read( int inumber, char *data, int length, int offset )
{
	return 0;
}

int fs_write( int inumber, const char *data, int length, int offset )
{
	return 0;
}