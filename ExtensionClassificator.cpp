/* 
 * File:   ExtensionClassificator.cpp
 * Author: themylogin
 * 
 * Created on 26 Март 2010 г., 20:06
 */

#include "ExtensionClassificator.h"

#include <boost/algorithm/string/case_conv.hpp>
#include <boost/filesystem/path.hpp>

#include <iostream>

ExtensionClassificator::ExtensionClassificator(std::string extension)
    : extension(extension)
{
    boost::algorithm::to_lower(this->extension);
}

ExtensionClassificator::~ExtensionClassificator()
{
}

bool ExtensionClassificator::is(Entry* entry)
{
    return getExtension(entry) == extension;
}

std::string ExtensionClassificator::getExtension(Entry* entry)
{
    std::string extension = boost::filesystem::path(entry->getName()).extension().native();
    boost::algorithm::to_lower(extension);
    return extension;
}
