#include <stdio.h>
#include <malloc.h>

#include "stdutils.h"

int getLenAllocArrStr (string *arreglo)
{
  return (malloc_usable_size(arreglo)/sizeof(string));
}
