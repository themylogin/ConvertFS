/* 
 * File:   AnyClassificator.h
 * Author: themylogin
 *
 * Created on 27 Март 2010 г., 8:12
 */

#ifndef _ANYCLASSIFICATOR_H
#define	_ANYCLASSIFICATOR_H

#include "Classificator.h"

class AnyClassificator : public Classificator
{
    public:
        AnyClassificator();
        virtual ~AnyClassificator();

        bool is(Entry* entry);
};

#endif	/* _ANYCLASSIFICATOR_H */

