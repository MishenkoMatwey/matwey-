#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
typedef struct Stack{ 
struct StackElem* topElem; 
} STACKT; 

struct StackElem{ 
char value[10000]; 
struct StackElem* next; 
}; 

void initStack(STACKT* p) 
{ 
p->topElem = NULL; 
} 
int isEmpty (STACKT* p) 
{ 
       if (p->topElem == NULL)
        return 0;
    else
        return 1;

} 


void push(STACKT* p, char *value)
{
     struct StackElem* tmp =  malloc(sizeof(struct StackElem*));
    strcpy(tmp-> value,value);
    tmp->next =p->topElem;
    p->topElem = tmp;
    printf("ok");
}
void pop(STACKT* p)
{
struct StackElem * clear = p ->topElem;  
struct StackElem* tmp = p->topElem; 
//printf("%s",p->topElem);
p->topElem = tmp->next; 
free(clear);
}

int search_file(char *dirPath,char *filename);
int read_file(char *adress ) 
{ STACKT* p = (STACKT*)malloc(sizeof(STACKT)); 

FILE * f = fopen(adress,"r");
if(!f)
return -1;

char s[100];
char s2[100];


    while (fgets(s,1000,f)){
if (strstr(s,"Deadlock")!=0 )
return 0;

else if  (strstr(s,"Minotaur")!=0 ){
push(p,adress);
return 1;}

else {
char* token = strtok(s," ");  
while (token!=NULL) {
strcpy(s2,token);
    token = strtok(NULL, " "); 
                    }
s2[strlen(s2) - 1] = '\0';
while(search_file("/Users/user/Desktop/😩/labyrinth",s2)){
push(p,adress);
  return 1;     }         
   }
}
}






int search_file(char *dirPath,char *filename)
{char nextadress[3000];
  strcat(nextadress,dirPath);
    DIR*dir=opendir(dirPath); 
 if (dir)
    { 
        struct  dirent *de = readdir(dir);  
        while (de) 
        {     
if(de->d_type == DT_DIR && strcmp(de->d_name, ".") != 0 && strcmp(de->d_name, "..") != 0)
{ 
int len = strlen(nextadress);
sprintf(nextadress, "%s/%s", dirPath,de->d_name);
if (search_file(nextadress,filename)==1){
closedir(dir);
return 1;
}
nextadress[len] = '\0';   
}
if(de->d_type == DT_REG && strcmp(de->d_name,filename) == 0)
{ int len = strlen(nextadress);
sprintf(nextadress, "%s/%s", dirPath,de->d_name);
//printf("%s\n",nextadress);
if (read_file(nextadress)==1){
closedir(dir);
return 1;}
nextadress[len] = '\0';  
}  
de = readdir(dir); }
       
}
    closedir(dir);
 return 0;
}

 int main (){
STACKT* p = (STACKT*)malloc(sizeof(STACKT));  char** s1 = (char**)calloc(100,sizeof(char*));   
 char* filename = (char*)malloc(sizeof(char) * 100);  
 filename="file.txt";

        FILE* ptrf = fopen("result.txt", "r");
    search_file("/Users/user/Desktop/😩/labyrinth",filename);  
    pop(p);
    //pop(p);
 }
