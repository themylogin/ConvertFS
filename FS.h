/* 
 * File:   FS.h
 * Author: themylogin
 *
 * Created on 27 Март 2010 г., 8:23
 */

#ifndef _FS_H
#define	_FS_H

#include "Context.h"

#include <fuse.h>

extern convertfs_context_t convertfs_context;

int convertfs_getattr(const char* path, struct stat* stbuf);
int convertfs_readdir(const char* path, void* buf, fuse_fill_dir_t filler, off_t offset, fuse_file_info* fi);
int convertfs_open(const char* path, fuse_file_info* fi);
int convertfs_read(const char* path, char* buf, size_t size, off_t offset, fuse_file_info* fi);
int convertfs_release(const char* path, fuse_file_info* fi);

#endif	/* _FS_H */

