#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>


void main(){

    char prol[7][10]={"S","A","A","B","B","C","C"};
    char pror[7][10]={"A","Bb","Cd","aB","@","Cc","@"};
    char prod[7][10]={"S->A","A->Bb","A->Cd","B->aB","B->@","C->Cc","C->@"};
    char first[7][10] = {"abcd", "ab", "cd", "a@", "@", "c@", "@"};
    char follow[7][10] = {"$", "$", "$", "a$", "b$", "c$", "d$"};

    char table[5][6][10];

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<6;j++)
            strcpy(table[i][j]," ");
    }

    int i,j,k;;

    int numr(char c)
    {
        if(c=='S') return 0;
        if(c=='A') return 1;
        if(c=='B') return 2;
        if(c=='C') return 3;
        if(c=='a') return 0;
        if(c=='b') return 1;
        if(c=='c') return 2;
        if(c=='d') return 3;
        if(c=='$') return 4;

        return 2;
    }

    for (i = 0; i < 7; i++) {
        k = strlen(first[i]);
        for (j = 0; j < 10; j++)
            if (first[i][j] != '@')
                strcpy(table[numr(prol[i][0]) + 1][numr(first[i][j]) + 1], prod[i]);

    }

    for (i = 0; i < 7; i++) {
        if (strlen(pror[i]) == 1) {
            if (pror[i][0] == '@') {
                k = strlen(follow[i]);
                for (j = 0; j < k; j++)
                    strcpy(table[numr(prol[i][0]) + 1][numr(follow[i][j]) + 1], prod[i]);
            }
        }
    }




    strcpy(table[0][0], " ");
    strcpy(table[0][1], "a");
    strcpy(table[0][2], "b");
    strcpy(table[0][3], "c");
    strcpy(table[0][4], "d");
    strcpy(table[0][5], "$");
    strcpy(table[1][0], "S");
    strcpy(table[2][0], "A");
    strcpy(table[3][0], "B");
    strcpy(table[4][0], "C");

    printf("\n--------------------------------------------------------\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 6; j++)
            printf("%-10s", table[i][j]);
        printf("\n--------------------------------------------------------\n");
    }

    return 0;

}
