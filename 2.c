#include<stdio.h>
#include<string.h>
void main(){

    char str[30];
    gets(str);

    int a$d=4;
    printf("%d",a$d);
    int size=strlen(str);

    if(str[0]=='/' && str[1]=='/')
        printf("It is comment");
    else if(str[0]=='/' && str[1]=='*' && str[size-1]=='/' && str[size-2]=='*')
    {
        printf("it is comment");
    }
    else
        printf("it is not comment");
}
