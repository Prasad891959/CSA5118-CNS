
#include <stdio.h>

int mod(int n) {
    return (n % 26 + 26) % 26;
}

int main() {
    int p[2][2], c[2][2], k[2][2];
    int det, inv = -1, i, j;

    printf("Enter plaintext matrix (2x2):\n");
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            scanf("%d", &p[i][j]);

    printf("Enter ciphertext matrix (2x2):\n");
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            scanf("%d", &c[i][j]);

    det = mod(p[0][0] * p[1][1] - p[0][1] * p[1][0]);

    for (i = 1; i < 26; i++) {
        if (mod(det * i) == 1) {
            inv = i;
            break;
        }
    }

    if (inv == -1) {
        printf("Plaintext matrix has no inverse.");
        return 0;
    }

    int adj[2][2] = {
        {p[1][1], -p[0][1]},
        {-p[1][0], p[0][0]}
    };

    int pinv[2][2];

    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            pinv[i][j] = mod(adj[i][j] * inv);

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            k[i][j] = 0;
            for (int x = 0; x < 2; x++)
                k[i][j] += c[i][x] * pinv[x][j];

            k[i][j] = mod(k[i][j]);
        }
    }

    printf("\nRecovered Hill Key:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++)
            printf("%d ", k[i][j]);
        printf("\n");
    }

    return 0;
}
