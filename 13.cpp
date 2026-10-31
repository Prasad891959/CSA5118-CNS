
#include <stdio.h>

int main()
{
    int P[2][2] = {{7, 11}, {4, 15}};
    int C[2][2] = {{7, 0}, {8, 19}};
    int K[2][2];

    int det, inverse;
    int i, j;

    det = (P[0][0]*P[1][1] -
           P[0][1]*P[1][0]) % 26;

    if(det < 0) det += 26;

    for(i = 1; i < 26; i++)
    {
        if((det * i) % 26 == 1)
        {
            inverse = i;
            break;
        }
    }

    int adj[2][2] = {
        {P[1][1], -P[0][1]},
        {-P[1][0], P[0][0]}
    };

    int inv[2][2];

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            inv[i][j] =
                (adj[i][j] * inverse) % 26;

            if(inv[i][j] < 0)
                inv[i][j] += 26;
        }
    }

    printf("Recovered Key Matrix:\n");

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            K[i][j] =
                (C[i][0]*inv[0][j] +
                 C[i][1]*inv[1][j]) % 26;

            printf("%d ", K[i][j]);
        }
        printf("\n");
    }

    return 0;
}
