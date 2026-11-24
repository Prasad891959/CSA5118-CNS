
#include <stdio.h>
#include <string.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int inverse(int a) {
    int i;
    for (i = 1; i < 26; i++) {
        if ((a * i) % 26 == 1)
            return i;
    }
    return -1;
}

int main() {
    char text[100];
    int a, b, i, choice, inv;

    printf("Enter message: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter a and b: ");
    scanf("%d%d", &a, &b);

    if (gcd(a, 26) != 1) {
        printf("Invalid key. Choose a coprime with 26.");
        return 0;
    }

    printf("1. Encrypt\n2. Decrypt\nEnter choice: ");
    scanf("%d", &choice);

    inv = inverse(a);

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            int x = text[i] - 'A';

            if (choice == 1)
                text[i] = ((a * x + b) % 26) + 'A';
            else if (choice == 2)
                text[i] = ((inv * (x - b + 26)) % 26) + 'A';
        }
    }

    printf("Result: %s", text);
    return 0;
}
