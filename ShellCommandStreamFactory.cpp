/* 
 * File:   ShellCommandStreamFactory.cpp
 * Author: themylogin
 * 
 * Created on 27 Март 2010 г., 8:48
 */

#include "ShellCommandStreamFactory.h"

#include "ShellCommandStream.h"

ShellCommandStreamFactory::ShellCommandStreamFactory(std::string command)
    : command(command)
{
}


ShellCommandStreamFactory::~ShellCommandStreamFactory()
{
}

Stream* ShellCommandStreamFactory::produce()
{
    return new ShellCommandStream(command);
}
