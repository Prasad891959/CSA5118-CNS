#include <stdio.h>

int main()
{
    unsigned int C, D;
    unsigned int C1, D1;
    int i, shift;

    printf("Enter 28-bit C value: ");
    scanf("%u", &C);

    printf("Enter 28-bit D value: ");
    scanf("%u", &D);

    C &= 0x0FFFFFFF;
    D &= 0x0FFFFFFF;

    printf("\nDES Subkey Generation:\n");

    for(i = 1; i <= 16; i++)
    {
        if(i == 1 || i == 2 || i == 9 || i == 16)
            shift = 1;
        else
            shift = 2;

        C1 = ((C << shift) | (C >> (28-shift)))
             & 0x0FFFFFFF;

        D1 = ((D << shift) | (D >> (28-shift)))
             & 0x0FFFFFFF;

        C = C1;
        D = D1;

        printf("Round %d\n", i);
        printf("C = %07X\n", C);
        printf("D = %07X\n", D);
    }

    printf("\nEach round combines selected bits from C and D to form a 48-bit DES subkey.");

    return 0;
}