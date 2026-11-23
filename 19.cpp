#include <stdio.h>

int main()
{
    unsigned int plain[10], cipher[10];
    unsigned int iv, previous;
    int n, i;

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter initialization vector: ");
    scanf("%u", &iv);

    previous = iv;

    printf("Enter plaintext blocks:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%u", &plain[i]);
    }

    printf("\nCBC Encryption:\n");

    for(i = 0; i < n; i++)
    {
        unsigned int x = plain[i] ^ previous;

        cipher[i] = x;

        printf("Cipher block %d = %u\n",
               i+1, cipher[i]);

        previous = cipher[i];
    }

    printf("\nCBC chaining completed.");

    return 0;
}