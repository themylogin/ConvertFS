/* 
 * File:   WindowsNamesFilter.cpp
 * Author: themylogin
 * 
 * Created on 26 Март 2010 г., 20:21
 */

#include "WindowsNamesFilter.h"

#include <boost/algorithm/string/replace.hpp>

WindowsNamesFilter::WindowsNamesFilter(std::string replaceInto)
    : replaceInto(replaceInto)
{
}

WindowsNamesFilter::~WindowsNamesFilter()
{
}

Entry* WindowsNamesFilter::apply(Entry* entry)
{
    std::string name = entry->getName();
    boost::algorithm::replace_all(name, "/",  replaceInto);
    boost::algorithm::replace_all(name, "\\",  replaceInto);
    boost::algorithm::replace_all(name, ":",  replaceInto);
    boost::algorithm::replace_all(name, "*",  replaceInto);
    boost::algorithm::replace_all(name, "?",  replaceInto);
    boost::algorithm::replace_all(name, "\"", replaceInto);
    boost::algorithm::replace_all(name, "<",  replaceInto);
    boost::algorithm::replace_all(name, ">",  replaceInto);
    boost::algorithm::replace_all(name, "|",  replaceInto);
    entry->setName(name);
    return entry;
}
