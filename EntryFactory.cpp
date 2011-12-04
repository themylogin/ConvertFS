/* 
 * File:   EntryFactory.cpp
 * Author: themylogin
 * 
 * Created on 27 Март 2010 г., 14:21
 */

#include "EntryFactory.h"

#include "RegularFileStreamFactory.h"

#include <unistd.h>

Entry* EntryFactory::realDirectoryEntry(std::string location, std::string name, std::string path)
{
    Entry *entry = new Entry;

    entry->setName(name);
    entry->setLocation(location);
    entry->setRealPath(path);
    entry->setType(Entry::Directory);

    struct stat* st = new struct stat;
    stat(path.c_str(), st);
    entry->setStat(st);

    entry->setNeedsCaching(false);

    return entry;
}

Entry* EntryFactory::realFileEntry(std::string location, std::string name, std::string path)
{
    Entry *entry = new Entry;

    entry->setName(name);
    entry->setLocation(location);
    entry->setRealPath(path);
    entry->setType(Entry::File);

    struct stat* st = new struct stat;
    stat(path.c_str(), st);
    entry->setStat(st);

    entry->setStreamFactory((StreamFactory*)new RegularFileStreamFactory(path));
    entry->setNeedsCaching(false);
    
    return entry;
}
