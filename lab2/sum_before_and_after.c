#include <stdlib.h>
#include <stdio.h>
#include "index_last_zero.h"
#include "index_first_zero.h"
int sum_before_and_after (int a[],int size)
{
int r=0,n=0,i,sum=0;
for (i=0;i<index_first_zero(a,size);i++)
{
n+=abs(a[i]);
}
for (i=index_last_zero(a, size);i<size;i++)
{
r+=abs(a[i]);
}
sum=r+n;
return sum;
}



