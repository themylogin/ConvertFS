/* 
 * File:   RegularFileStream.cpp
 * Author: themylogin
 * 
 * Created on 27 Март 2010 г., 14:03
 */

#include "RegularFileStream.h"

RegularFileStream::RegularFileStream(std::string filename)
{
    file.open(filename.c_str(), std::ios::binary);
}

RegularFileStream::~RegularFileStream()
{
}

bool RegularFileStream::useDirectIo()
{
    return true;
}

int RegularFileStream::read(char* buf, size_t size, off_t offset)
{
    boost::mutex::scoped_lock lock(mutex);
    file.seekg(offset, std::ios::beg);
    return file.readsome(buf, size);
}
