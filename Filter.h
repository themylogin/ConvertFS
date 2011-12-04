/* 
 * File:   Filter.h
 * Author: themylogin
 *
 * Created on 26 Март 2010 г., 19:36
 */

#ifndef _FILTER_H
#define	_FILTER_H

#include "Entry.h"

class Filter
{
    public:
        virtual ~Filter(){}
        virtual Entry* apply(Entry* entry) = 0;
};

#endif	/* _FILTER_H */

