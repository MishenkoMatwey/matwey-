#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
int search_file(char *dirPath,char *filename);
int read_file(char *adress ) 
{
FILE * f = fopen(adress,"r");
if(!f)
return -1;

char s[100];
char s2[100];


    while (fgets(s,1000,f)){
if (strstr(s2,"Deadlock")!=0 )
return 0;

else if  (strstr(s2,"Minotaur")!=0 ){
FILE* ptr_res=fopen("result.txt","a");
fprintf (ptr_res,"%s\n",adress);
fclose(ptr_res);
return 1;}

else {
char* token = strtok(s," ");  
while (token!=NULL) {
strcpy(s2,token);printf ("%s\n",s2);
    token = strtok(NULL, " "); 
                    }
    s2[strlen(s2) - 1] = '\0';
if (search_file("/Users/user/Desktop/😩/labyrinth",s2)){
FILE* ptr_res=fopen("result.txt","a");
fprintf (ptr_res,"%s\n",adress);
fclose(ptr_res);
  printf("ergw");
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

if (read_file(nextadress)==1){
closedir(dir);printf("%s",nextadress);
return 1;}
nextadress[len] = '\0';  
}  
de = readdir(dir); }
       
}
    closedir(dir);
 return 0;
}

 int main (){

 char** s1 = (char**)calloc(100,sizeof(char*));   
 char* filename = (char*)malloc(sizeof(char) * 100);  
 filename="file.txt";

        FILE* ptrf = fopen("result.txt", "r");
    search_file("/Users/user/Desktop/😩/labyrinth",filename);  
 }