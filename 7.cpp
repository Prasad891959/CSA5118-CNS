
#include <stdio.h>
#include <string.h>

int main()
{
    char cipher[100], key[27];
    int i, j;

    printf("Enter ciphertext: ");
    scanf("%s", cipher);

    printf("Enter key: ");
    scanf("%s", key);

    printf("Decrypted text: ");

    for(i = 0; cipher[i] != '\0'; i++)
    {
        for(j = 0; j < 26; j++)
        {
            if(cipher[i] == key[j])
            {
                printf("%c", 'A' + j);
                break;
            }
        }
    }

    return 0;
}
