#include <stdio.h>

int main()
{
    int i;

    printf("ECB MODE:\n");

    printf("Error in C1 affects only P1.\n");

    printf("\nCBC MODE:\n");

    printf("Error in C1 affects P1 and P2.\n");

    printf("P1 is corrupted completely.\n");

    printf("Corresponding bit in P2 is changed.\n");

    printf("P3 and remaining blocks are not affected.\n");

    printf("\nSource plaintext P1 error:\n");

    printf("It affects C1 and all subsequent ciphertext blocks.\n");

    return 0;
}