#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n, m, g;

    printf("Enter RSA modulus n: ");
    scanf("%d", &n);

    printf("Enter plaintext block m: ");
    scanf("%d", &m);

    g = gcd(n, m);

    printf("GCD = %d\n", g);

    if (g > 1 && g < n) {
        printf("A factor of n is found: %d\n", g);
        printf("RSA modulus can be factorized.\n");
    } else {
        printf("No non-trivial common factor found.\n");
    }

    return 0;
}