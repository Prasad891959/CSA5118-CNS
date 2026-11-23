#include <stdio.h>

long long power(long long a, long long x, long long q) {
    long long r = 1;

    while (x > 0) {
        if (x % 2 == 1)
            r = (r * a) % q;

        a = (a * a) % q;
        x = x / 2;
    }

    return r;
}

int main() {
    long long q, a, x, y;
    long long A, B, key1, key2;

    printf("Enter prime number q: ");
    scanf("%lld", &q);

    printf("Enter primitive root a: ");
    scanf("%lld", &a);

    printf("Enter Alice private key: ");
    scanf("%lld", &x);

    printf("Enter Bob private key: ");
    scanf("%lld", &y);

    A = power(a, x, q);
    B = power(a, y, q);

    key1 = power(B, x, q);
    key2 = power(A, y, q);

    printf("\nAlice sends: %lld\n", A);
    printf("Bob sends: %lld\n", B);
    printf("Alice shared key: %lld\n", key1);
    printf("Bob shared key: %lld\n", key2);

    return 0;
}