#include <stdio.h>
int index_first_zero();
int main ()
{
int m,i,a[10];
for (i=0;i<10;i++)
if (a[i]==0)
	{
	m=i;
	break ;
	}
printf("%d\n",m);


}

