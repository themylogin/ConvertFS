/* 
 * File:   Dispatcher.h
 * Author: themylogin
 *
 * Created on 26 Март 2010 г., 19:35
 */

#ifndef _DISPATCHER_H
#define	_DISPATCHER_H

#include "Classificator.h"
#include "Entry.h"
#include "Filter.h"

#include <vector>

class Dispatcher
{
    public:
        Dispatcher();
        virtual ~Dispatcher();

        void addRule(Classificator* classificator, Filter* filter);
        Entry* processEntry(Entry* entry);

    protected:
        std::vector< std::pair<Classificator*, Filter*> > rules;
};

#endif	/* _DISPATCHER_H */

