/* 
 * File:   Entry.h
 * Author: themylogin
 *
 * Created on 26 Март 2010 г., 19:38
 */

#ifndef _ENTRY_H
#define	_ENTRY_H

#include "StreamFactory.h"

#include <unistd.h>

#include <string>

class Entry
{
    public:
        enum Type { Directory, File };

        Entry();
        virtual ~Entry();

        std::string getName();
        void setName(std::string name);

        std::string getLocation();
        void setLocation(std::string location);

        std::string getPath();

        std::string getRealPath();
        void setRealPath(std::string realPath);

        StreamFactory* getStreamFactory();
        void setStreamFactory(StreamFactory* streamFactory);

        bool needsCaching();
        void setNeedsCaching(bool needsCaching);

        Type getType();
        void setType(Type type);

        struct stat* getStat();
        void setStat(struct stat* st);

    protected:
        std::string name;
        std::string location;
        std::string realPath;
        StreamFactory* streamFactory;
        bool _needsCaching;

        Type type;
        struct stat* st;
};

#endif	/* _ENTRY_H */

