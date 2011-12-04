/* 
 * File:   Classificator.h
 * Author: themylogin
 *
 * Created on 26 Март 2010 г., 19:57
 */

#ifndef _CLASSIFICATOR_H
#define	_CLASSIFICATOR_H

#include "Entry.h"

class Classificator
{
    public:
        virtual ~Classificator(){}
        virtual bool is(Entry* entry) = 0;
};

#endif	/* _CLASSIFICATOR_H */

