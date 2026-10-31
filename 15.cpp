
#include <stdio.h>
#include <string.h>

int main()
{
    char text[100];
    int i, key;

    printf("Enter ciphertext: ");
    scanf("%s", text);

    printf("\nPossible plaintexts:\n");

    for(key = 0; key < 26; key++)
    {
        printf("Key %d: ", key);

        for(i = 0; text[i] != '\0'; i++)
        {
            int p = (text[i] - 'A' - key + 26) % 26;
            printf("%c", p + 'A');
        }

        printf("\n");
    }

    return 0;
}
