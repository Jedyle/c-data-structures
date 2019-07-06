#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

#define ASSERT(cond)  if (!(cond)){ printf("Function %s failed\n", __func__); exit(-1);}
#define SUCCESS       printf("Function %s succeeded !\n", __func__);

#endif
