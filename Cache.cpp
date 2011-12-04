/* 
 * File:   Cache.cpp
 * Author: themylogin
 * 
 * Created on 2 Апрель 2010 г., 16:42
 */

#include "Cache.h"

#include "RegularFileStream.h"

#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>

#include <string.h>

Cache::Cache(std::string directory)
    : directory(directory)
{
}

Cache::~Cache()
{
}

bool Cache::hasEntry(Entry* entry)
{
    std::string cachedPath = directory + "/" + entry->getPath();
    if (boost::filesystem::is_regular(cachedPath))
    {
        std::string metadataPath = directory + "/" + entry->getPath() + ".convertfs-cache";
        std::ifstream metadata(metadataPath.c_str());
        if (metadata.is_open())
        {
            std::string mtime; getline(metadata, mtime);
            std::string size; getline(metadata, size);

            std::ostringstream real_mtime; real_mtime << entry->getStat()->st_mtim.tv_sec;
            std::ostringstream real_size; real_size << entry->getStat()->st_size;
            if (real_mtime.str() == mtime &&
                real_size.str() == size)
            {
                return true;
            }
            else
            {
                boost::filesystem::remove(cachedPath);
                boost::filesystem::remove(metadataPath);
            }
        }
    }

    return false;
}

struct stat* Cache::entryStat(Entry* entry)
{
    struct stat* st = new struct stat;
    memcpy(st, entry->getStat(), sizeof(struct stat));
    st->st_size = boost::filesystem::file_size(directory + "/" + entry->getPath());
    return st;
}

Stream* Cache::entryStream(Entry* entry)
{
    return new RegularFileStream(directory + "/" + entry->getPath());
}

void Cache::storeEntry(Entry* entry, Stream* src)
{
    std::string cachePath = directory + "/" + entry->getPath();
    
    boost::filesystem::create_directories(boost::filesystem::path(cachePath).parent_path());
    std::fstream out(cachePath.c_str(), std::ios::out);
    if (out.is_open())
    {
        int read;
        int pos = 0;
        char tmp[8192];
        while ((read = src->read(tmp, sizeof(tmp), pos)) > 0)
        {
            out.write(tmp, sizeof(tmp));
            pos += read;
        }
    }

    std::ofstream metadataOut((cachePath + ".convertfs-cache").c_str(), std::ios::out);
    if (metadataOut.is_open())
    {
        struct stat st;
        stat(entry->getRealPath().c_str(), &st);
        metadataOut << st.st_mtim.tv_sec << "\n"
                    << st.st_size << "\n";
    }
}
