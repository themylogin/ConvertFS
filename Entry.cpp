/* 
 * File:   Entry.cpp
 * Author: themylogin
 * 
 * Created on 26 Март 2010 г., 19:38
 */

#include "Entry.h"

Entry::Entry()
{
    streamFactory = 0;
    st = 0;
}


Entry::~Entry()
{
}

std::string Entry::getName()
{
    return name;
}

void Entry::setName(std::string name)
{
    this->name = name;
}

std::string Entry::getLocation()
{
    return location;
}

void Entry::setLocation(std::string path)
{
    this->location = path;
}

std::string Entry::getPath()
{
    return getLocation() + "/" + getName();
}

std::string Entry::getRealPath()
{
    return realPath;
}

void Entry::setRealPath(std::string realPath)
{
    this->realPath = realPath;
}

StreamFactory* Entry::getStreamFactory()
{
    return streamFactory;
}

void Entry::setStreamFactory(StreamFactory* streamFactory)
{
    if (this->streamFactory != 0)
    {
        delete this->streamFactory;
    }

    this->streamFactory = streamFactory;
}

bool Entry::needsCaching()
{
    return _needsCaching;
}

void Entry::setNeedsCaching(bool needsCaching)
{
    this->_needsCaching = needsCaching;
}

Entry::Type Entry::getType()
{
    return type;
}

void Entry::setType(Entry::Type type)
{
    this->type = type;
}

struct stat* Entry::getStat()
{
    return st;
}

void Entry::setStat(struct stat* st)
{
    if (this->st != 0)
    {
        delete this->st;
    }

    this->st = st;
}
