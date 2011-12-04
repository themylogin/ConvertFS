/* 
 * File:   RegularFileStreamFactory.cpp
 * Author: themylogin
 * 
 * Created on 27 Март 2010 г., 13:59
 */

#include "RegularFileStreamFactory.h"

#include "RegularFileStream.h"

RegularFileStreamFactory::RegularFileStreamFactory(std::string filename)
    : filename(filename)
{
}

RegularFileStreamFactory::~RegularFileStreamFactory()
{
}

Stream* RegularFileStreamFactory::produce()
{
    return new RegularFileStream(filename);
}
