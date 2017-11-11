#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "index_last_zero.h"
#include "index_first_zero.h"
int sum_between (int *a,int size)
{
int n=0,i;
for (i = index_first_zero(a, size);i < index_last_zero(a, size);i++)
{
n+=abs(a[i]);
}
return n;
}
