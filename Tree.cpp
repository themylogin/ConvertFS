/* 
 * File:   Tree.cpp
 * Author: themylogin
 * 
 * Created on 27 Март 2010 г., 14:15
 */

#include "Tree.h"

#include "EntryFactory.h"

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/filesystem.hpp>

Tree::Tree(std::string realRootPath, Dispatcher* dispatcher)
    : dispatcher(dispatcher)
{
    map[""] = EntryFactory::realDirectoryEntry("", "", realRootPath);
}

Tree::~Tree()
{
    for (_EntryMap::const_iterator it = map.begin(); it != map.end(); ++it)
    {
        delete it->second;
    }
}

Entry* Tree::getEntry(std::string path)
{
    std::string trimmedPath = trimPath(path);
    _EntryMap::iterator it = map.find(trimmedPath);
    if (it != map.end())
    {
        return it->second;
    }

    std::string pathParent = trimmedPathParent(trimmedPath);
    getEntriesFromDir(pathParent, true);
    it = map.find(trimmedPath);
    if (it != map.end())
    {
        return it->second;
    }

    return 0;
}

EntryCollection* Tree::getEntriesFromDir(std::string path, bool onlyUpdateMap)
{
    Entry* dir = getEntry(path);
    if (dir == 0)
    {
        return 0;
    }

    EntryCollection* result = 0;
    if (!onlyUpdateMap)
    {
        result = new EntryCollection;
    }
    boost::filesystem::directory_iterator end;
    for (boost::filesystem::directory_iterator it(dir->getRealPath()); it != end; ++it)
    {
        Entry* entry;
        if (boost::filesystem::is_directory(it->status()))
        {
            entry = EntryFactory::realDirectoryEntry(path, it->path().filename().native(), it->path().native());
        }
        else if (boost::filesystem::is_regular_file(it->status()))
        {
            entry = EntryFactory::realFileEntry(path, it->path().filename().native(), it->path().native());
        }
        else
        {
            continue;
        }
        entry = dispatcher->processEntry(entry);
        if (entry)
        {
            if (!onlyUpdateMap)
            {
                result->push_back(entry);
            }

            std::string entryTrimmedPath = trimPath(trimPath(path) + "/" + entry->getName());
            _EntryMap::iterator it = map.find(entryTrimmedPath);
            if (it != map.end())
            {
                delete it->second;
                map[entryTrimmedPath] = entry;
            }
            else
            {
                map[entryTrimmedPath] = entry;
            }
        }
    }
    return result;
}

std::string Tree::trimPath(std::string path)
{
    std::string result = path;
    boost::algorithm::trim_left_if(result, boost::is_any_of("/"));
    boost::algorithm::trim_right_if(result, boost::is_any_of("/"));

    return result;
}

std::string Tree::trimmedPathParent(std::string trimmedPath)
{
    size_t lastSlashPosition = trimmedPath.rfind("/");
    if (lastSlashPosition != std::string::npos)
    {
        return trimmedPath.substr(0, lastSlashPosition);
    }
    else
    {
        return std::string("");
    }
}
