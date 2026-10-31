
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char matrix[5][5] = {
        {'M','F','H','I','K'},
        {'U','N','O','P','Q'},
        {'Z','V','W','X','Y'},
        {'E','L','A','R','G'},
        {'D','S','T','B','C'}
    };

    char text[100];
    int i, j, r1, c1, r2, c2;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Encrypted text: ");

    for(i = 0; text[i] != '\0'; )
    {
        if(!isalpha(text[i]))
        {
            i++;
            continue;
        }

        char a = toupper(text[i++]);
        char b = 'X';

        if(text[i] != '\0' && isalpha(text[i]))
            b = toupper(text[i++]);

        if(a == 'J') a = 'I';
        if(b == 'J') b = 'I';

        for(j = 0; j < 25; j++)
        {
            if(matrix[j/5][j%5] == a)
            {
                r1 = j/5;
                c1 = j%5;
            }

            if(matrix[j/5][j%5] == b)
            {
                r2 = j/5;
                c2 = j%5;
            }
        }

        if(r1 == r2)
        {
            printf("%c%c",
            matrix[r1][(c1+1)%5],
            matrix[r2][(c2+1)%5]);
        }
        else if(c1 == c2)
        {
            printf("%c%c",
            matrix[(r1+1)%5][c1],
            matrix[(r2+1)%5][c2]);
        }
        else
        {
            printf("%c%c",
            matrix[r1][c2],
            matrix[r2][c1]);
        }
    }

    return 0;
}
