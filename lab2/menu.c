#include <stdio.h>
#include <stdlib.h>
#include "sum_before_and_after.h"
#include "sum_between.h"
#include "index_last_zero.h"
#include "index_first_zero.h"
int main (){
int a[100],number,size = 0,i = 0;
char c;
	scanf("%d\n",&number);
while(size<100){
scanf("%d", &a[i++]);
size++;
if ((c=getchar())=='\n'){
break;	
}
}

switch (number) {
	case 0:
		printf("%d\n",index_first_zero (a,size));
		break;
	case 1:
		printf("%d\n", index_last_zero(a, size));
		break;
	case 2:
		printf("%d\n",sum_between(a, size));
		break;
	case 3:
		printf("%d\n",sum_before_and_after(a, size));
		break;	
	default:
		printf("Данные некорректны\n");
		break;
	}
return 0;
}
