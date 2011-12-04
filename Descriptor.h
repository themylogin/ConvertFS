/* 
 * File:   Descriptor.h
 * Author: themylogin
 *
 * Created on 31 Март 2010 г., 21:01
 */

#ifndef _DESCRIPTOR_H
#define	_DESCRIPTOR_H

#include "Entry.h"
#include "Stream.h"

class Descriptor
{
    public:
        Descriptor(Entry* entry, Stream* stream, bool streamNeedsCaching);
        virtual ~Descriptor();

        Entry* getEntry();
        Stream* getStream();
        bool streamNeedsCaching();
        
    private:
        Entry* entry;
        Stream* stream;
        bool _streamNeedsCaching;
};

#endif	/* _DESCRIPTOR_H */

