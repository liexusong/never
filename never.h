#ifndef __NEVER_H__
#define __NEVER_H__

#include "func.h"

typedef struct never
{
    func_list * funcs;
} never;

never * never_new(func_list * funcs);
void never_delete(never * nev);

#endif /* __NEVER_H__ */

