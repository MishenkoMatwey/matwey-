#include <stdio.h>
int  index_first_zero (int *a,int size) {
int m;

for (int i=0;i<size;i++) {
    if (a[i]==0) {
	m=i;
        break;
	}    
    }
return m;
}


