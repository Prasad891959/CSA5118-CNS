#include <stdio.h>

int power(int a, int b, int p) {
    int r = 1;

    while (b > 0) {
        r = (r * a) % p;
        b--;
    }

    return r;
}

int main() {
    int p = 23, q = 11, g = 4;
    int x = 3, h = 4;
    int k1 = 2, k2 = 3;
    int r1, r2, s1, s2;

    r1 = power(g, k1, p) % q;
    r2 = power(g, k2, p) % q;

    s1 = (6 * (h + x * r1)) % q;
    s2 = (4 * (h + x * r2)) % q;

    printf("First signature: (%d, %d)\n", r1, s1);
    printf("Second signature: (%d, %d)\n", r2, s2);

    return 0;
}