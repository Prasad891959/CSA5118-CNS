#include <stdio.h>

int main() {
    int plaintext[3] = {1, 2, 4};
    int keystream[3] = {56, 77, 50};
    int i, ciphertext;

    printf("CTR mode XOR demonstration\n");

    for (i = 0; i < 3; i++) {
        ciphertext = plaintext[i] ^ keystream[i];
        printf("Ciphertext block %d: %d\n", i + 1, ciphertext);
    }

    return 0;
}