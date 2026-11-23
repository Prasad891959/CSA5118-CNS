#include <stdio.h>

long long modpow(long long a, long long e, long long n) {
    long long r = 1;

    while (e > 0) {
        if (e % 2 == 1)
            r = (r * a) % n;

        a = (a * a) % n;
        e = e / 2;
    }

    return r;
}

int main() {
    long long n, e, c;
    int found = 0;

    printf("Enter n: ");
    scanf("%lld", &n);

    printf("Enter public key e: ");
    scanf("%lld", &e);

    printf("Enter ciphertext: ");
    scanf("%lld", &c);

    for (int m = 0; m < 26; m++) {
        if (modpow(m, e, n) == c) {
            printf("Plaintext letter: %c\n", 'A' + m);
            found = 1;
        }
    }

    if (!found)
        printf("No matching letter found.\n");

    return 0;
}