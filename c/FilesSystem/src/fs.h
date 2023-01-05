#ifndef FS_H
#define FS_H

void fs_debug();
int  fs_format();
int  fs_mount();
int getFreeInode();
int  fs_create();
int  fs_delete( int inumber );
int  fs_getsize();
int getFreeBlock();
void unmount();
int getBlockNumByte(int inumber , int offset);

void copy( int permission, int nBlock , char *data, int iterations, int offset1 , int offset2);
int  fs_read( int inumber, char *data, int length, int offset );
int  fs_write( int inumber, const char *data, int length, int offset );

#endif