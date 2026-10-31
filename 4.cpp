
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[100], key[30];
    char matrix[5][5];
    int used[26] = {0};
    int i, j, k = 0;

    printf("Enter keyword: ");
    scanf("%s", key);

    printf("Enter plaintext: ");
    scanf("%s", text);

    used['J' - 'A'] = 1;

    for(i = 0; key[i] != '\0'; i++)
    {
        char ch = toupper(key[i]);

        if(ch == 'J') ch = 'I';

        if(!used[ch - 'A'])
        {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    for(i = 0; i < 26; i++)
    {
        if(!used[i])
        {
            matrix[k / 5][k % 5] = 'A' + i;
            k++;
        }
    }

    printf("\nEncrypted text: ");

    for(i = 0; text[i] != '\0'; i += 2)
    {
        int r1, c1, r2, c2;

        char a = toupper(text[i]);
        char b = text[i + 1] ?
                 toupper(text[i + 1]) : 'X';

        if(a == 'J') a = 'I';
        if(b == 'J') b = 'I';

        for(j = 0; j < 25; j++)
        {
            if(matrix[j / 5][j % 5] == a)
            {
                r1 = j / 5;
                c1 = j % 5;
            }

            if(matrix[j / 5][j % 5] == b)
            {
                r2 = j / 5;
                c2 = j % 5;
            }
        }

        if(r1 == r2)
        {
            printf("%c%c",
            matrix[r1][(c1 + 1) % 5],
            matrix[r2][(c2 + 1) % 5]);
        }
        else if(c1 == c2)
        {
            printf("%c%c",
            matrix[(r1 + 1) % 5][c1],
            matrix[(r2 + 1) % 5][c2]);
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
S