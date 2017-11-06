#include <stdio.h>
void index_last_zero ();
int main()
{
int b,i,a[10];
for (i=10;i>=0;i--)
if (a[i]==0)
        {
        b=i;
        break ;
        }
printf("%d\n",b);


}

