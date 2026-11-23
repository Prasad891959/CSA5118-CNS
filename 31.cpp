#include <stdio.h>

int main() {
    unsigned long long L, K1, K2;
    int bits;

    printf("Enter block size (64 or 128): ");
    scanf("%d", &bits);

    if (bits == 64) {
        printf("Enter 64-bit value in hexadecimal: ");
        scanf("%llx", &L);

        K1 = L << 1;
        if (L >> 63)
            K1 ^= 0x1B;

        K2 = K1 << 1;
        if (K1 >> 63)
            K2 ^= 0x1B;

        printf("K1 = %016llX\n", K1);
        printf("K2 = %016llX\n", K2);
        printf("Rb = 1B\n");
    }
    else if (bits == 128) {
        printf("For 128-bit CMAC, use Rb = 87.\n");
        printf("A 128-bit implementation requires 16-byte values.\n");
    }
    else {
        printf("Invalid block size.\n");
    }

    return 0;
}