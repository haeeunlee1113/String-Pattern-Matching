
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_STRING_SIZE 100000
#define MAX_PATTERN_SIZE 100

char str[MAX_STRING_SIZE];
char ptr[MAX_PATTERN_SIZE];

int failure[MAX_PATTERN_SIZE];
int nfind(char *string, char *pat);
int main () {

    //string 파일읽어오기
    FILE *string = NULL;
    string = fopen("string.txt","r");
    if(string==NULL)
    {
        printf("The string file does not exist.");
        exit(0);
    }

    //pattern 파일 읽어오기
    FILE *pattern = NULL;
    pattern = (fopen("pattern.txt","r"));
    if(pattern==NULL)
    {
        printf("The pattern file does not exist.");
        exit(0);
    }

    fgets(str,MAX_STRING_SIZE,string);
    fgets(ptr,MAX_PATTERN_SIZE,string);

    nfind(str,ptr);

    int findpattern;

    if(findpattern == -1){
        printf("The pattern %s was not found in the string.\n", pattern);
    } else {
        printf("The pattern %s was found at position %d in the string.\n", pattern, findpattern);
    }
    FILE *result = NULL;
    result = fopen("result_naive.txt", "w");


    fclose(result);


}


int nfind(char *str, char *ptr) {

    int i=0, j=0;
    int lens = strlen(str);
    int lenp = strlen(ptr);

    while(i < lens && j < lenp) {
        if(str[i] == ptr[j]) { i++; j++; }
        else if(j == 0) i++;
        else j = failure[j-1] + 1;
    }
    return ((j==lenp) ? (i-lenp) : -1);

}