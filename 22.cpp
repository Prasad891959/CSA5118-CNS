#include <stdio.h>

int main() {
    int p[4] = {0, 1, 35, 0};
    int iv = 170, previous = iv;
    int i, c;

    printf("CBC XOR demonstration\n");

    for (i = 0; i < 4; i++) {
        c = p[i] ^ previous;
        printf("Block %d: %d\n", i + 1, c);
        previous = c;
    }

    return 0;
}