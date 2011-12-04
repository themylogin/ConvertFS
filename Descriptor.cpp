/* 
 * File:   Descriptor.cpp
 * Author: themylogin
 * 
 * Created on 31 Март 2010 г., 21:01
 */

#include "Descriptor.h"

Descriptor::Descriptor(Entry* entry, Stream* stream, bool streamNeedsCaching)
    : entry(entry), stream(stream), _streamNeedsCaching(streamNeedsCaching)
{
}

Descriptor::~Descriptor()
{
    delete stream;
}

Entry* Descriptor::getEntry()
{
    return entry;
}

Stream* Descriptor::getStream()
{
    return stream;
}

bool Descriptor::streamNeedsCaching()
{
    return _streamNeedsCaching;
}
