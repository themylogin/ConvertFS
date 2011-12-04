/* 
 * File:   RegularFileStreamFactory.h
 * Author: themylogin
 *
 * Created on 27 Март 2010 г., 13:59
 */

#ifndef _REGULARFILESTREAMFACTORY_H
#define	_REGULARFILESTREAMFACTORY_H

#include "StreamFactory.h"

#include <string>

class RegularFileStreamFactory : public StreamFactory
{
    public:
        RegularFileStreamFactory(std::string filename);
        virtual ~RegularFileStreamFactory();

        Stream* produce();
        
    protected:
        std::string filename;

};

#endif	/* _REGULARFILESTREAMFACTORY_H */

