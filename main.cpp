/* 
 * File:   main.cpp
 * Author: themylogin
 *
 * Created on 26 Март 2010 г., 19:34
 */

#include <fuse.h>
#include <stdlib.h>
#include <string.h>
#include <libxml/xmlreader.h>
#include <vector>
#include <string>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>

#include "FS.h"
#include "AnyClassificator.h"
#include "WindowsNamesFilter.h"
#include "ExtensionClassificator.h"
#include "ConvertFilter.h"
#include "IgnoreFilter.h"

/*
 * 
 */
int main(int argc, char** argv)
{
    struct { char* settingsFile; } settings;
    fuse_opt shellOptions[] =
    {
        { "settings=%s", 0, NULL },
        { NULL }
    };
    fuse_args arguments = FUSE_ARGS_INIT(argc, argv);
    if (fuse_opt_parse(&arguments, &settings, shellOptions, NULL) == -1)
    {
        return (EXIT_FAILURE);
    }

    LIBXML_TEST_VERSION
    convertfs_context.cache = 0;
    Dispatcher* dispatcher = new Dispatcher;
    xmlTextReaderPtr reader = xmlReaderForFile(settings.settingsFile, NULL, 0);
    while (xmlTextReaderRead(reader) == 1)
    {
        const xmlChar* name = xmlTextReaderConstName(reader);
        if (!strcmp((const char*)name, "rule"))
        {
            Classificator* classificator = 0;
            Filter* filter = 0;
            const xmlChar* classificatorType = xmlTextReaderGetAttribute(reader, (const xmlChar*)"classificator-type");
            const xmlChar* classificatorData = xmlTextReaderGetAttribute(reader, (const xmlChar*)"classificator-data");
            const xmlChar* filterType = xmlTextReaderGetAttribute(reader, (const xmlChar*)"filter-type");
            const xmlChar* filterData = xmlTextReaderGetAttribute(reader, (const xmlChar*)"filter-data");
            if (!strcmp((const char*)classificatorType, "any"))
            {
                classificator = new AnyClassificator;
            }
            else if (!strcmp((const char*)classificatorType, "ext"))
            {
                classificator = new ExtensionClassificator((const char*)classificatorData);
            }

            if (!strcmp((const char*)filterType, "ignore"))
            {
                filter = new IgnoreFilter;
            }
            else if (!strcmp((const char*)filterType, "windows-names"))
            {
                filter = new WindowsNamesFilter("_");
            }
            else if (!strcmp((const char*)filterType, "command"))
            {
                std::vector<std::string> v;
                std::string s((const char*)filterData);
                boost::algorithm::split(v, s, boost::is_any_of(","));
                filter = new ConvertFilter(v[1], v[0]);
            }

            if (filter && classificator)
            {
                dispatcher->addRule(classificator, filter);
            }
        }
        else if (!strcmp((const char*)name, "source"))
        {
            const xmlChar* directory = xmlTextReaderGetAttribute(reader, (const xmlChar*)"directory");
            convertfs_context.tree = new Tree((const char*)directory, dispatcher);
        }
        else if (!strcmp((const char*)name, "cache"))
        {
            const xmlChar* directory = xmlTextReaderGetAttribute(reader, (const xmlChar*)"directory");
            const xmlChar* enabled = xmlTextReaderGetAttribute(reader, (const xmlChar*)"enabled");
            if (!strcmp((const char*)enabled, "1"))
            {
                convertfs_context.cache = new Cache((const char *)directory);
            }
        }
    }

    fuse_operations operations;
    memset(&operations, 0, sizeof(fuse_operations));
    operations.getattr = convertfs_getattr;
    operations.readdir = convertfs_readdir;
    operations.open    = convertfs_open;
    operations.read    = convertfs_read;
    operations.release = convertfs_release;

    return fuse_main(arguments.argc, arguments.argv, &operations, NULL);
}

