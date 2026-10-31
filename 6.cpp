
#include <stdio.h>
#include <string.h>

int main()
{
    char text[100];
    int i, key, p;

    printf("Enter ciphertext: ");
    scanf("%s", text);

    printf("\nPossible plaintexts:\n");

    for(key = 1; key < 26; key++)
    {
        if(key == 13 || key == 2 ||
           key == 4 || key == 6 ||
           key == 8 || key == 10 ||
           key == 12 || key == 14 ||
           key == 16 || key == 18 ||
           key == 20 || key == 22 ||
           key == 24)
            continue;

        printf("Key %d: ", key);

        for(i = 0; text[i] != '\0'; i++)
        {
            p = text[i] - 'A';
            p = (p - 3 + 26) % 26;
            printf("%c", p + 'A');
        }

        printf("\n");
    }

    return 0;
}
