/* 
 * File:   IgnoreFilter.h
 * Author: themylogin
 *
 * Created on 26 Март 2010 г., 19:54
 */

#ifndef _IGNOREFILTER_H
#define	_IGNOREFILTER_H

#include "Filter.h"

class IgnoreFilter : public Filter
{
    public:
        IgnoreFilter();
        virtual ~IgnoreFilter();

        Entry* apply(Entry* entry);
};

#endif	/* _IGNOREFILTER_H */

