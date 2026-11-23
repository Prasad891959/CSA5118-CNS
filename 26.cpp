#include <stdio.h>

int main() {
    int n, e, d, newe;

    printf("Enter RSA modulus n: ");
    scanf("%d", &n);

    printf("Enter old public key e: ");
    scanf("%d", &e);

    printf("Enter leaked private key d: ");
    scanf("%d", &d);

    printf("Enter new public exponent: ");
    scanf("%d", &newe);

    printf("\nOld public key: (%d, %d)\n", e, n);
    printf("Leaked private key: (%d, %d)\n", d, n);
    printf("New public key: (%d, %d)\n", newe, n);

    printf("\nSame modulus is being reused.\n");
    printf("This is not considered safe.\n");
    printf("Generate a completely new RSA key pair.\n");

    return 0;
}