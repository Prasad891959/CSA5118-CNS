
#include <stdio.h>
#include <string.h>

double freq[26] = {
    8.12, 1.49, 2.71, 4.32, 12.02, 2.30, 2.03,
    5.92, 7.31, 0.10, 0.69, 3.98, 2.61, 6.95,
    7.68, 1.82, 0.11, 6.02, 6.28, 9.10, 2.88,
    1.11, 2.09, 0.17, 2.11, 0.07
};

int main() {
    char text[500], result[500];
    double score[26];
    int count[26], i, k, j, n = 0;

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    for (k = 0; k < 26; k++) {
        for (i = 0; i < 26; i++)
            count[i] = 0;

        n = 0;

        for (i = 0; text[i] != '\0'; i++) {
            if (text[i] >= 'A' && text[i] <= 'Z') {
                count[(text[i] - 'A' - k + 26) % 26]++;
                n++;
            } else if (text[i] >= 'a' && text[i] <= 'z') {
                count[(text[i] - 'a' - k + 26) % 26]++;
                n++;
            }
        }

        score[k] = 0;

        if (n > 0) {
            for (i = 0; i < 26; i++) {
                double expected = freq[i] * n / 100.0;
                double difference = count[i] - expected;

                score[k] += difference * difference / expected;
            }
        }
    }

    printf("\nPossible plaintexts:\n");

    for (j = 0; j < 10; j++) {
        int best = -1;

        for (k = 0; k < 26; k++) {
            if (best == -1 || score[k] < score[best])
                best = k;
        }

        printf("\nShift %d: ", best);

        for (i = 0; text[i] != '\0'; i++) {
            if (text[i] >= 'A' && text[i] <= 'Z')
                printf("%c", 'A' + (text[i] - 'A' - best + 26) % 26);
            else if (text[i] >= 'a' && text[i] <= 'z')
                printf("%c", 'a' + (text[i] - 'a' - best + 26) % 26);
            else
                printf("%c", text[i]);
        }

        score[best] = 1e9;
    }

    return 0;
}
