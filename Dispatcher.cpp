/* 
 * File:   Dispatcher.cpp
 * Author: themylogin
 * 
 * Created on 26 Март 2010 г., 19:35
 */

#include "Dispatcher.h"

Dispatcher::Dispatcher()
{
}

Dispatcher::~Dispatcher()
{
    for (std::vector< std::pair<Classificator*, Filter*> >::const_iterator it = rules.begin(); it != rules.end(); ++it)
    {
        delete (*it).first;
        delete (*it).second;
    }
}

void Dispatcher::addRule(Classificator* classificator, Filter* filter)
{
    rules.push_back(std::pair<Classificator*, Filter*>(classificator, filter));
}

Entry* Dispatcher::processEntry(Entry* entry)
{
    for (std::vector< std::pair<Classificator*, Filter*> >::const_iterator it = rules.begin(); it != rules.end() && entry; ++it)
    {
        if ((*it).first->is(entry))
        {
            Filter* f = (*it).second;
            entry = f->apply(entry);
        }
    }

    return entry;
}
