#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define text_size 100  
#define number_of_words 10
#define STACK_MAX_SIZE 200

typedef struct Stack_tag {
    int data[STACK_MAX_SIZE];
    size_t size;
} Stack_t;


int NULL_STACK (Stack_t *stack) 
{ 
         if (stack->size == 0)
        return 0;
    else
        return 1;
        
} 
void size(const Stack_t *stack) {
    
    printf("%d\n",(int) stack->size);
    
}

void push_n(Stack_t *stack, const  int value) {
   
    stack->data[stack->size] = value;
    stack->size++;
       printf("ok\n");
}


int  top(const Stack_t *stack) {
    printf("%d\n",(stack->data[stack->size-1]));
    return stack->data[stack->size - 1];
}

 int pop(Stack_t *stack) {
    
    stack->size--;
    printf("%d\n",stack->data[stack->size]);
    return stack->data[stack->size];
}
 


int main()
{ 
Stack_t stack;
stack.size = 0;
char f5[] = "exit";    
int i=0;
int count= 1; 
  
  char c;
 int j=0;
int memory=2;

char* str = (char*) malloc(memory* sizeof(char)); 
char** str1 = (char**) malloc(sizeof(char*) * number_of_words); 

while ((strstr(str,f5)) == NULL) 
{ 
str[i] = getchar(); 
i++; 
memory++; 
str = (char*)realloc(str, memory * sizeof(char)); 
} 


char* token = strtok(str, " \n"); 
 i=0; 
for(i = 0; token != NULL; i++) {
    if(i == number_of_words * count - 1) {
    count++; 
    str1  = (char**) realloc(str1 , number_of_words* count * sizeof(char*)); 
    } 
 str1 [i] = token; 
    token = strtok(NULL, " \n"); 
    } 
    
 char f1[] = "top";
 char f2[] = "push";
 char f3[] = "pop";
 char f4[] = "size";

   
    
for (j=0;j<i;j++){
      if ((strcmp(str1[j],f1)==0) && (NULL_STACK(&stack)!=0)) 
   top(&stack);
    else  if ((strcmp(str1[j],f1)==0) && (NULL_STACK(&stack)==0)) 
      {printf ("error\n");
    break;
    }    

    if (strcmp(str1[j],f2)==0) 
    { int n=atoi(str1[j+1]);
    push_n(&stack,(int)n);

    }
  
     
    if ((strcmp(str1[j],f3)==0) && (NULL_STACK(&stack)!=0)) 
    {
        pop(&stack);
    
    }
    else if ((strcmp(str1[j],f3)==0) && (NULL_STACK(&stack)==0))
    {printf ("error\n");
    break;
    }    
    if (strcmp(str1[j],f4)==0) 
    size(&stack);
    

    if (j==(i-1)) 
    {printf("bye\n");
    break;
    }
    }   
 

}