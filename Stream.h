/* 
 * File:   Stream.h
 * Author: themylogin
 *
 * Created on 27 Март 2010 г., 8:40
 */

#ifndef _STREAM_H
#define	_STREAM_H

#include <fuse.h>

class Stream
{
    public:
        virtual ~Stream(){}

        virtual bool useDirectIo() = 0;
        virtual int read(char* buf, size_t size, off_t offset) = 0;
};

#endif	/* _STREAM_H */

