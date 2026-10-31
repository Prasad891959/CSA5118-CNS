
#include <stdio.h>
#include <math.h>

int main()
{
    double keys;
    double uniqueKeys;

    keys = 1;

    for(int i = 1; i <= 25; i++)
    {
        keys = keys * i;
    }

    uniqueKeys = keys / 4;

    printf("Total possible keys = %.0f\n", keys);

    printf("Approximate power of 2 = 2^%.2f\n",
           log2(keys));

    printf("Effectively unique keys = %.0f\n",
           uniqueKeys);

    return 0;
}
