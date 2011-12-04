/* 
 * File:   ConvertFilter.h
 * Author: themylogin
 *
 * Created on 27 Март 2010 г., 8:51
 */

#ifndef _CONVERTFILTER_H
#define	_CONVERTFILTER_H

#include "Filter.h"

class ConvertFilter : public Filter
{
    public:
        ConvertFilter(std::string commandTemplate, std::string newExtension);
        virtual ~ConvertFilter();

        Entry* apply(Entry* entry);

    protected:
        std::string commandTemplate;
        std::string newExtension;
};

#endif	/* _CONVERTFILTER_H */

