/* 
 * File:   IgnoreFilter.cpp
 * Author: themylogin
 * 
 * Created on 26 Март 2010 г., 19:54
 */

#include "IgnoreFilter.h"

IgnoreFilter::IgnoreFilter()
{
}

IgnoreFilter::~IgnoreFilter()
{
}

Entry* IgnoreFilter::apply(Entry* entry)
{
    delete entry;
    return 0;
}
