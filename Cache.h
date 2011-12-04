/* 
 * File:   Cache.h
 * Author: themylogin
 *
 * Created on 2 Апрель 2010 г., 16:42
 */

#ifndef _CACHE_H
#define	_CACHE_H

#include "Entry.h"
#include "Stream.h"

#include <string>

class Cache
{
    public:
        Cache(std::string directory);
        virtual ~Cache();

        bool hasEntry(Entry* entry);
        struct stat* entryStat(Entry* entry);
        Stream* entryStream(Entry* entry);
        void storeEntry(Entry* entry, Stream* src);

    protected:
        std::string directory;
};

#endif	/* _CACHE_H */

