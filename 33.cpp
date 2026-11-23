
#include <stdio.h>
#include <stdint.h>

int main() {
    uint64_t plaintext, key;
    uint64_t encrypted, decrypted;

    printf("Enter 64-bit plaintext (in hexadecimal): ");
    scanf("%llx", (unsigned long long *)&plaintext);

    printf("Enter 64-bit key (in hexadecimal): ");
    scanf("%llx", (unsigned long long *)&key);

    /* Demonstration using XOR */
    encrypted = plaintext ^ key;
    decrypted = encrypted ^ key;

    printf("\nEncrypted: %016llX",
           (unsigned long long)encrypted);

    printf("\nDecrypted: %016llX\n",
           (unsigned long long)decrypted);

    return 0;
}
