/* 
 * File:   ConvertFilter.cpp
 * Author: themylogin
 * 
 * Created on 27 Март 2010 г., 8:51
 */

#include "ConvertFilter.h"

#include "ShellCommandStreamFactory.h"

#include <boost/algorithm/string/replace.hpp>
#include <boost/filesystem.hpp>

ConvertFilter::ConvertFilter(std::string commandTemplate, std::string newExtension)
    : commandTemplate(commandTemplate), newExtension(newExtension)
{
}

ConvertFilter::~ConvertFilter()
{
}

Entry* ConvertFilter::apply(Entry* entry)
{
    entry->setName(boost::filesystem::path(entry->getName()).replace_extension(newExtension).string());

    std::string escapedSourceFilename = entry->getRealPath();
    boost::algorithm::replace_all(escapedSourceFilename, "'", "'\\''");
    std::string command = commandTemplate;    
    boost::algorithm::replace_last(command, "%s", escapedSourceFilename);
    entry->setStreamFactory(new ShellCommandStreamFactory(command));
    entry->setNeedsCaching(true);

    entry->getStat()->st_size = 0;

    return entry;
}
