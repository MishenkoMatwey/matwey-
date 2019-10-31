#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main ()
{
	char* text=(char*)malloc(10000*sizeof(char));
	char c;
	int i=0,n=0,m=0,len=0,fl=0;
	while ((c=getchar()) !='\n')
		{
		text[i++]=c ;
		}

	for (i=0;i<10000;i++)
		{
		if (text[i] == '.' || text[i] == '?' || text[i] == ';') 
			{
				i++;   		 
				text[i] = '\n';
			}		    
                if (text[i]=='\t')
			{
				text[i]=0;   
			}	      
				

		}

	 if (text[i] == '.' || text[i] == '?' || text[i] == ';')
	{
                len=i;
                for (i>0;i<len;i++){
                if (isalpha(text[i]) ==0 &&  text[i-1] !=' ')

                        {
                        i=i-len;
                        printf("%c",text[len]);
                        }

                else
                printf("%c",text[len]);
                        i++;

                                    }
         }



return 0;
}























