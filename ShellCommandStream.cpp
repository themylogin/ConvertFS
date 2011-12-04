/* 
 * File:   ShellCommandStream.cpp
 * Author: themylogin
 * 
 * Created on 1 Апрель 2010 г., 14:35
 */

#include "ShellCommandStream.h"

#include <memory.h>
#include <stdio.h>

class ShellCommandStreamThread
{
    public:
        ShellCommandStreamThread(ShellCommandStream* dst, std::string command)
            : dst(dst), command(command)
        {
        }

        void operator()()
        {
            FILE* p = 0;

            try
            {
                if (p = popen(command.c_str(), "r"))
                {
                    int read;
                    char tmp[8192];
                    while ((read = fread(tmp, 1, sizeof(tmp), p)) > 0)
                    {
                        boost::this_thread::interruption_point();
                        boost::mutex::scoped_lock lock(dst->mutex);

                        if (dst->availableInBuffer + read > dst->bufferSize)
                        {
                            dst->buffer = (char*) realloc(dst->buffer, dst->bufferSize + BUFFER_CHUNK);
                            dst->bufferSize += BUFFER_CHUNK;
                        }

                        memcpy(dst->buffer + dst->availableInBuffer, tmp, read * sizeof(char));
                        dst->availableInBuffer += read;
                    }
                }

                dst->finished = true;
            }
            catch (boost::thread_interrupted)
            {
            }

            if (p != 0)
            {
                fclose(p);
            }
        }

        static const int BUFFER_CHUNK = 1024 * 1024;

    private:
        ShellCommandStream* dst;
        std::string command;
};

ShellCommandStream::ShellCommandStream(std::string command)
{
    availableInBuffer = 0;
    finished = false;

    bufferSize = ShellCommandStreamThread::BUFFER_CHUNK;
    buffer = (char*) malloc(bufferSize * sizeof(char));

    thread = boost::thread(ShellCommandStreamThread(this, command));
}

ShellCommandStream::~ShellCommandStream()
{
    thread.join();
    free(buffer);
}

bool ShellCommandStream::useDirectIo()
{
    return true;
}

int ShellCommandStream::read(char* buf, size_t size, off_t offset)
{
    start:
    if (offset + size <= availableInBuffer)
    {
        boost::mutex::scoped_lock lock(mutex);
        memcpy(buf, buffer + offset, size * sizeof(char));
        return size;
    }
    else
    {
        if (finished)
        {
            size_t bytesLeft = availableInBuffer - offset;
            if (bytesLeft <= 0)
            {
                return 0;
            }
            else
            {
                boost::mutex::scoped_lock lock(mutex);
                memcpy(buf, buffer + offset, size * sizeof(char));
                return bytesLeft;
            }
        }
        else
        {
            while (offset + size > availableInBuffer && !finished)
            {
                usleep(1000);
            }
            goto start; // avoid unnecessary recursion
        }
    }
}
