/* 
 * File:   EntryFactory.h
 * Author: themylogin
 *
 * Created on 27 Март 2010 г., 14:21
 */

#ifndef _ENTRYFACTORY_H
#define	_ENTRYFACTORY_H

#include "Entry.h"

class EntryFactory
{
    public:
        static Entry* realDirectoryEntry(std::string location, std::string name, std::string path);
        static Entry* realFileEntry(std::string location, std::string name, std::string path);
};

#endif	/* _ENTRYFACTORY_H */

