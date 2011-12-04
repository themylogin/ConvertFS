/* 
 * File:   ExtensionClassificator.h
 * Author: themylogin
 *
 * Created on 26 Март 2010 г., 20:06
 */

#ifndef _EXTENSIONCLASSIFICATOR_H
#define	_EXTENSIONCLASSIFICATOR_H

#include "Classificator.h"

#include <string>

class ExtensionClassificator : public Classificator
{
    public:
        ExtensionClassificator(std::string extension);
        virtual ~ExtensionClassificator();

        bool is(Entry* entry);

    protected:
        std::string extension;
        std::string getExtension(Entry* entry);
};

#endif	/* _EXTENSIONCLASSIFICATOR_H */

