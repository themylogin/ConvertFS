/* 
 * File:   Tree.h
 * Author: themylogin
 *
 * Created on 27 Март 2010 г., 14:15
 */

#ifndef _TREE_H
#define	_TREE_H

#include "Dispatcher.h"
#include "Entry.h"
#include "EntryCollection.h"

#include <map>
#include <string>

typedef std::map<std::string, Entry*> _EntryMap;

class Tree
{
    public:
        Tree(std::string realRootPath, Dispatcher* dispatcher);
        virtual ~Tree();

        Entry* getEntry(std::string path);
        EntryCollection* getEntriesFromDir(std::string path, bool onlyUpdateMap = false);
        
    protected:
        _EntryMap map;
        std::string getEntryFromMap(std::string path);

        Dispatcher* dispatcher;

        std::string trimPath(std::string path);
        std::string trimmedPathParent(std::string trimmedPath);
};

#endif	/* _TREE_H */

