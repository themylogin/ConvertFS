/* 
 * File:   WindowsNamesFilter.h
 * Author: themylogin
 *
 * Created on 26 Март 2010 г., 20:21
 */

#ifndef _WINDOWSNAMESFILTER_H
#define	_WINDOWSNAMESFILTER_H

#include "Filter.h"

class WindowsNamesFilter : public Filter
{
    public:
        WindowsNamesFilter(std::string replaceInto);
        virtual ~WindowsNamesFilter();

        Entry* apply(Entry* entry);

    protected:
       std::string replaceInto;
};

#endif	/* _WINDOWSNAMESFILTER_H */

