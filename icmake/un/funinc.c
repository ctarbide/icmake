#include "icmun.h"

void fun_inc ()
{
    INT16
        index;

    index = getint16 (infile);
    dumpint (index);
    if ((UNS16)index < 0x8000)
        printf ("inc global %s %s\n", varname (var [index].type),
                                    printvar (index));
    else if (index < (INT16) 0xc000)
        printf ("inc local %s %s\n",
                   varname (local_types[ (INT16) 0xc000 - (INT16) 1 - index]),
                   printvar (index));
    else
        printf ("inc arg %s\n", printvar (index));
}