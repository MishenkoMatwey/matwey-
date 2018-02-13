#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define text_size 1001  
#define word_size 31  
#define number_of_words 10

int function(const void* a, const void* b) {
return (strcmp(*(char**) a, *(char**) b)); 
} 

int main() { 
int count= 1; 
char* word = (char*) malloc(word_size * sizeof(char)); 
char* text = (char*) malloc(text_size * sizeof(char)); 
char** text2 = (char**) malloc(sizeof(char*) * number_of_words); 
fgets(text, text_size, stdin);
scanf("%s",word);
text[strlen(text)-1] = '\0'; 

char* token = strtok(text, " ."); 
int i=0; 
for(i = 0; token != NULL; i++) {
    if(i == number_of_words * count - 1) {
    count++; 
    text2  = (char**) realloc(text2 , number_of_words* count * sizeof(char*)); 
    } 
  text2 [i] = token; 
    token = strtok(NULL, " ."); 
    } 

    qsort(text2 , i, sizeof(char*), function);

    char* ptr = (char*) bsearch(&word, text2 , i, sizeof(char*), function); 
        if(ptr != NULL) 
        printf("exists"); 
        else 
        printf("doesn't exist"); 
        return 0; 
        }
