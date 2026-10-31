
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char key[30], text[100];
    char matrix[5][5];
    int used[26] = {0};
    int i, j, k = 0;
    int r1, c1, r2, c2;

    printf("Enter keyword: ");
    scanf("%29s", key);

    printf("Enter plaintext: ");
    scanf(" %[^\n]", text);

    used['J' - 'A'] = 1;

    for(i = 0; key[i] != '\0'; i++)
    {
        char ch = toupper(key[i]);

        if(ch == 'J')
            ch = 'I';

        if(isalpha(ch) && !used[ch - 'A'])
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

    printf("\nPlayfair Matrix:\n");

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
            printf("%c ", matrix[i][j]);

        printf("\n");
    }

    char clean[200], result[200];
    int n = 0, len = 0;

    for(i = 0; text[i] != '\0'; i++)
    {
        char ch = toupper(text[i]);

        if(isalpha(ch))
        {
            if(ch == 'J')
                ch = 'I';

            clean[n++] = ch;
        }
    }

    clean[n] = '\0';

    for(i = 0; i < n; )
    {
        char a = clean[i];
        char b;

        if(i + 1 >= n)
        {
            b = 'X';
            i++;
        }
        else if(clean[i] == clean[i + 1])
        {
            b = 'X';
            i++;
        }
        else
        {
            b = clean[i + 1];
            i += 2;
        }

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
            result[len++] = matrix[r1][(c1 + 1) % 5];
            result[len++] = matrix[r2][(c2 + 1) % 5];
        }
        else if(c1 == c2)
        {
            result[len++] = matrix[(r1 + 1) % 5][c1];
            result[len++] = matrix[(r2 + 1) % 5][c2];
        }
        else
        {
            result[len++] = matrix[r1][c2];
            result[len++] = matrix[r2][c1];
        }
    }

    result[len] = '\0';

    printf("\nEncrypted text: %s\n", result);

    return 0;
}
