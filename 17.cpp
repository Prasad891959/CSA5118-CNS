#include <stdio.h>

int main()
{
    int key[16];
    int i;

    printf("Enter 16 encryption round keys:\n");

    for(i = 0; i < 16; i++)
    {
        scanf("%d", &key[i]);
    }

    printf("\nDES Decryption Key Order:\n");

    for(i = 15; i >= 0; i--)
    {
        printf("Round %d : K%d = %d\n",
               16-i, i+1, key[i]);
    }

    printf("\nDecryption uses keys in reverse order.");

    return 0;
}