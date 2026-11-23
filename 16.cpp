#include <stdio.h>
#include <ctype.h>

int main()
{
    char text[1000];
    char frequency[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int count[26] = {0};
    int used[26] = {0};
    char key[26];
    int i, j, max;

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    for(i = 0; text[i] != '\0'; i++)
    {
        if(isalpha(text[i]))
            count[toupper(text[i]) - 'A']++;
    }

    for(i = 0; i < 26; i++)
    {
        max = -1;

        for(j = 0; j < 26; j++)
        {
            if(!used[j] && (max == -1 || count[j] > count[max]))
                max = j;
        }

        used[max] = 1;
        key[max] = frequency[i];
    }

    printf("\nPossible plaintext:\n");

    for(i = 0; text[i] != '\0'; i++)
    {
        if(isalpha(text[i]))
        {
            char c = key[toupper(text[i]) - 'A'];

            if(islower(text[i]))
                printf("%c", tolower(c));
            else
                printf("%c", c);
        }
        else
            printf("%c", text[i]);
    }

    return 0;
}