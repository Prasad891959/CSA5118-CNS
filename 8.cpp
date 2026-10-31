
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char key[30], text[100], cipher[27];
    int i, j, k = 0, used[26] = {0};

    printf("Enter keyword: ");
    scanf("%s", key);

    printf("Enter plaintext: ");
    scanf("%s", text);

    for(i = 0; key[i] != '\0'; i++)
    {
        char ch = toupper(key[i]);

        if(ch >= 'A' && ch <= 'Z' && !used[ch-'A'])
        {
            cipher[k++] = ch;
            used[ch-'A'] = 1;
        }
    }

    for(i = 0; i < 26; i++)
    {
        if(!used[i])
            cipher[k++] = 'A' + i;
    }

    cipher[k] = '\0';

    printf("Encrypted text: ");

    for(i = 0; text[i] != '\0'; i++)
    {
        j = toupper(text[i]) - 'A';
        printf("%c", cipher[j]);
    }

    return 0;
}
