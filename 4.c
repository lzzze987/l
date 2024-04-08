#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

void main(){

    char s[20];
    gets(s);
    int sz=strlen(s);
    int flag=1;

    if(isalpha(s[0])==0 && s[0]!='_')
        flag=0;


    else if(isalpha(s[0])==1 || s[0]=='_')
    {
        for(int i=1;i<sz;i++)
        {
           if(isalpha(s[0])==0 && s[0]!='_')
           flag=0;
           break;
        }

    }

    if(flag==0)
        printf("not valid identifier");
    else
        printf("valid identifier");
}
