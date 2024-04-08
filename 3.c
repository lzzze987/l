#include <stdio.h>

int main() {
    char s[20];
    int state = 0, i = 0;

    printf("Enter a string: ");
    scanf("%s", s);

    while (s[i] != '\0') {
        switch (state) {
            case 0:
                if (s[i] == 'a') state = 1;
                else if (s[i] == 'b') state = 2;
                else state = 6;
                break;
            case 1:
                if (s[i] == 'a') state = 3;
                else if (s[i] == 'b') state = 4;
                else state = 6;
                break;
            case 2:
                if (s[i] == 'b') state = 2;
                else state = 6;
                break;
            case 3:
                if (s[i] == 'a') state = 3;
                else if (s[i] == 'b') state = 2;
                else state = 6;
                break;
            case 4:
                if (s[i] == 'b') state = 5;
                else state = 6;
                break;
            case 5:
                if (s[i] == 'b') state = 2;
                else state = 6;
                break;
            default:
                printf("\n%s is not recognized.\n", s);
                return 0;
        }
        i++;
    }

    if (state == 1) printf("\n%s is accepted under rule 'a*'\n", s);
    else if (state == 2 || state == 4) printf("\n%s is accepted under rule 'a*b+'\n", s);
    else if (state == 5) printf("\n%s is accepted under rule 'abb'\n", s);

    return 0;
}
