/* 
 * File:   ShellCommandStreamFactory.h
 * Author: themylogin
 *
 * Created on 27 Март 2010 г., 8:48
 */

#ifndef _SHELLCOMMANDSTREAMFACTORY_H
#define	_SHELLCOMMANDSTREAMFACTORY_H

#include "StreamFactory.h"

#include <string>

class ShellCommandStreamFactory : public StreamFactory
{
    public:
        ShellCommandStreamFactory(std::string command);
        virtual ~ShellCommandStreamFactory();

        Stream* produce();

    protected:
        std::string command;
};

#endif	/* _SHELLCOMMANDSTREAMFACTORY_H */

