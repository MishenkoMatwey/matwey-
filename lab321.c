#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
        int main() 
{ 
    int memory = 1; 
    int memory2 = 1; 
    char* text = (char*)malloc(memory * sizeof(char)); 
    char* text2 = (char*)malloc(memory2 * sizeof(char)); 
    void* check = NULL; 
    char endoftext[] = "Dragon flew away!"; 
    int i = 0, n = 0, m = 0, number = 0, j = 0, mass2 = 0, start_offer = 0, length = 0; 
while ((check = strstr(text,endoftext)) == NULL) 
    { 
        text[i] = getchar(); 
        i++; 
        memory++; 
        text = (char*)realloc(text, memory * sizeof(char)); 
    } 
    length = i-1; 


for (i = 0; i <= length; i++) 
    { 
        if (text[i] >= '0' && text[i] <= '9' && text[i - 1] != ' ' && text[i + 1] != ' ' && text[i + 1] != '.' && text[i + 1] != '?' && text[i + 1] != ';') 
        { 
        number = 1; 
        i++; 
        continue; 
        } 

    if (text[i] == '.' || text[i] == '?' || text[i] == ';' || i == length) 
    {    
        if (number == 0) 
        { 
            for (j = start_offer; j <= i; j++) 
            {    
            text2[mass2] = text[j]; 
            mass2++; 
            memory2++; 
            text2 = (char*)realloc(text2, memory2 * sizeof(char)); 
            } 
        } 
    start_offer = i + 1; 
    number = 0; 
    n++; 
    } 
    } 

for (i = 0; i < mass2; i++) 
{ 
        if (text2[i] == '.' || text2[mass2] == '?' || text[mass2] == ';' || (i+1 == mass2)) 
        { 
        m++; 
        text2[i + 1] = '\n'; 
        } 
        if (text2[i] == '\t') 
        {    
        text2[i] = '\0'; 
        } 

} 

for (i = 0; i <= mass2; i++) 
        { 
        printf("%c", text2[i]); 
        } 

printf("Количество предложений до %i и количество предложений после %i\n", n - 1, m); 
free(text); 
free(text2); 
return 0; 
}