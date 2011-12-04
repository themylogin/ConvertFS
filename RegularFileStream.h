/* 
 * File:   RegularFileStream.h
 * Author: themylogin
 *
 * Created on 27 Март 2010 г., 14:03
 */

#ifndef _REGULARFILESTREAM_H
#define	_REGULARFILESTREAM_H

#include "Stream.h"

#include <boost/thread/mutex.hpp>

#include <fstream>
#include <string>

class RegularFileStream : public Stream
{
    public:
        RegularFileStream(std::string filename);
        virtual ~RegularFileStream();

        bool useDirectIo();
        int read(char* buf, size_t size, off_t offset);
        
    private:
        boost::mutex mutex;
        std::ifstream file;
};

#endif	/* _REGULARFILESTREAM_H */

