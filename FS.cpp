#include "FS.h"
#include "Descriptor.h"

#include <errno.h>
#include <string.h>

convertfs_context_t convertfs_context;

int convertfs_getattr(const char* path, struct stat* stbuf)
{
    Entry* entry = convertfs_context.tree->getEntry(path);
    if (entry == 0)
    {
        return -ENOENT;
    }    

    if (convertfs_context.cache && convertfs_context.cache->hasEntry(entry))
    {
        struct stat* st = convertfs_context.cache->entryStat(entry);
        memcpy(stbuf, st, sizeof(struct stat));
        delete st;
    }
    else
    {
        memcpy(stbuf, entry->getStat(), sizeof(struct stat));
    }

    return 0;
}

int convertfs_readdir(const char* path, void* buf, fuse_fill_dir_t filler, off_t offset, fuse_file_info* fi)
{
    (void) offset;
    (void) fi;

    EntryCollection* c = convertfs_context.tree->getEntriesFromDir(path);
    for (EntryCollection::iterator it = c->begin(); it != c->end(); ++it)
    {
        Entry* entry = *it;

        if (convertfs_context.cache && convertfs_context.cache->hasEntry(entry))
        {
            struct stat* st = convertfs_context.cache->entryStat(entry);
            filler(buf, entry->getName().c_str(), st, 0);
            delete st;
        }
        else
        {
            filler(buf, entry->getName().c_str(), entry->getStat(), 0);
        }
    }

    return 0;
}

int convertfs_open(const char* path, fuse_file_info* fi)
{
    Entry* entry = convertfs_context.tree->getEntry(path);
    if (entry == 0)
    {
        return -ENOENT;
    }

    Stream* stream;
    bool streamNeedsCaching;
    if (convertfs_context.cache && convertfs_context.cache->hasEntry(entry))
    {
        stream = convertfs_context.cache->entryStream(entry);
        streamNeedsCaching = false;
    }
    else
    {
        stream = entry->getStreamFactory()->produce();
        streamNeedsCaching = entry->needsCaching();
    }
    
    Descriptor* descriptor = new Descriptor(entry, stream, streamNeedsCaching);
    fi->direct_io = stream->useDirectIo();
    fi->fh = (uint64_t)descriptor;

    return 0;
}

int convertfs_read(const char* path, char* buf, size_t size, off_t offset, fuse_file_info* fi)
{
    Descriptor* descriptor = (Descriptor*)fi->fh;
    return descriptor->getStream()->read(buf, size, offset);
}

int convertfs_release(const char* path, fuse_file_info* fi)
{
    Descriptor* descriptor = (Descriptor*)fi->fh;

    if (convertfs_context.cache && descriptor->streamNeedsCaching())
    {
        convertfs_context.cache->storeEntry(descriptor->getEntry(), descriptor->getStream());
    }

    delete descriptor;
    return 0;
}
