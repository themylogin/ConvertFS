/* 
 * File:   ShellCommandStream.h
 * Author: themylogin
 *
 * Created on 1 Апрель 2010 г., 14:35
 */

#ifndef _SHELLCOMMANDSTREAM_H
#define	_SHELLCOMMANDSTREAM_H

#include "Stream.h"

#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>

#include <string>

class ShellCommandStream : public Stream
{
    friend class ShellCommandStreamThread;

    public:
        ShellCommandStream(std::string command);
        virtual ~ShellCommandStream();

        bool useDirectIo();
        int read(char* buf, size_t size, off_t offset);

    protected:
        char* buffer;
        size_t bufferSize;
        size_t availableInBuffer;
        bool finished;

        boost::mutex mutex;
        boost::thread thread;
};

#endif	/* _SHELLCOMMANDSTREAM_H */

