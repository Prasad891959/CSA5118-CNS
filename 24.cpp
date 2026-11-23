#include <stdio.h>

int gcdExtended(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int g = gcdExtended(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return g;
}

int main() {
    int n = 3599, e = 31;
    int p = 0, q = 0, x, y, d;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            p = i;
            q = n / i;
            break;
        }
    }

    int phi = (p - 1) * (q - 1);

    gcdExtended(e, phi, &x, &y);

    d = (x % phi + phi) % phi;

    printf("p = %d\n", p);
    printf("q = %d\n", q);
    printf("Phi(n) = %d\n", phi);
    printf("Private key d = %d\n", d);

    return 0;
}