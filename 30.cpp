#include <stdio.h>

int encrypt(int value, int key) {
    return (value + key) % 256;
}

int main() {
    int key, x, tag;
    int second, forgedTag;

    printf("Enter key: ");
    scanf("%d", &key);

    printf("Enter message block X: ");
    scanf("%d", &x);

    tag = encrypt(x, key);

    second = x ^ tag;

    forgedTag = encrypt(second ^ tag, key);

    printf("\nOriginal message: %d\n", x);
    printf("Original MAC tag: %d\n", tag);
    printf("Forged second block: %d\n", second);
    printf("Forged message: %d %d\n", x, second);
    printf("Forged MAC tag: %d\n", forgedTag);

    return 0;
}