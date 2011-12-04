/* 
 * File:   StreamFactory.h
 * Author: themylogin
 *
 * Created on 27 Март 2010 г., 8:42
 */

#ifndef _STREAMFACTORY_H
#define	_STREAMFACTORY_H

#include "Stream.h"

class StreamFactory
{
    public:
        virtual ~StreamFactory(){}

        virtual Stream* produce() = 0;
};

#endif	/* _STREAMFACTORY_H */

