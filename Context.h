/* 
 * File:   Context.h
 * Author: themylogin
 *
 * Created on 27 Март 2010 г., 8:25
 */

#ifndef _CONTEXT_H
#define	_CONTEXT_H

#include "Cache.h"
#include "Tree.h"

typedef struct
{
    Cache* cache;
    Tree* tree;
} convertfs_context_t;

#endif	/* _CONTEXT_H */

