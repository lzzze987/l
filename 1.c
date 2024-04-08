#include<string.h>
#include<ctype.h>
#include<stdio.h>


void keyword(char str[10])
{
    if(strcmp("for",str)==0||strcmp("while",str)==0||strcmp("do",str)==0|| strcmp("int",str)==0||strcmp("float",str)==0||strcmp("char",str)==0||strcmp("double",str)==0||
    strcmp("static",str)==0||strcmp("switch",str)==0||strcmp("case",str)==0)
    printf("\n%s is a keyword",str);
    else
    printf("\n%s is an identifier",str);
}
void main(){

    // initial
    char c, str[10], str1[10];
    int lineno=0;
    int tokenvalue=0; int i=0,j=0,k=0;
    int num[100];
    FILE *f1, *f2, *f3;

    printf("Enter C program");

    // open file f1, as input and take user input
    f1=fopen("input", "w");

    // get user input
    while((c=getchar())!=EOF)
        putc(c,f1);
    //close f1
    fclose(f1);

    f1=fopen("input", "r");
    f2=fopen("identifier", "w");
    f3=fopen("specialchar", "w");

    while((c=getc(f1))!=EOF)
    {
        if(isdigit(c))
        {
            // if it is starting with number then definately it's not an identifier
            tokenvalue=c-'0';
            c=getc(f1);
            while(isdigit(c))
            {
                tokenvalue=tokenvalue*10+c-'0';
                c=getc(f1);
            }
            num[i++]=tokenvalue;
            // now c contain a non digit because while loop broke, but pointer got moved ahead to next char so
            ungetc(c,f1);
        }
        else if(isalpha(c))
        {
            // it can be identifier or a keyword if start form alphabet
            putc(c,f2);
            c=getc(f1);
            // continue till identifier exist
            while(isdigit(c) || isalpha(c) || c=='_')
            {
                putc(c,f2);
                c=getc(f1);
            }
            putc(' ',f2);
            ungetc(c,f1);

        }
        else if(c==' ' || c=='\t')
        {
            printf(" ");
        }
        else if(c=='\n')
        {
            lineno++;
        }
        else
        {
            // all special charcters
            putc(c,f3);
        }
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);

    // print the numbers stored in num array
    printf("The numbers in program are : ");
    for(int j=0;j<i;j++)
        printf("%d", num[j]);

    printf("\n");

    f2=fopen("identifier", "r");
    k=0;
    printf("The keyword and identifier are");

    while((c=getc(f2))!=EOF)
    {
        // construct the string
        if(c!=' ')
        {
            str[k++]=c;
        }
        else
        {
            str[k]='\0';
            keyword(str);
            k=0;
        }
    }
    fclose(f2);

    f3=fopen("specialchar" ,"r");
    printf("special charcters are");
    while((c=getc(f3))!=EOF)
    {
        printf("%c",c);
        printf(" ");
    }
    printf("\n");
    fclose(f3);

    printf("total lines are %d", lineno);

}
