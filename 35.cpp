#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100];
    int key[100], len, i;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    len = strcspn(text, "\n");
    text[len] = '\0';

    printf("Enter %d key numbers (0 to 25): ", len);

    for (i = 0; i < len; i++) {
        scanf("%d", &key[i]);

        if (key[i] < 0 || key[i] > 25) {
            printf("Invalid key value.\n");
            return 1;
        }
    }

    printf("Ciphertext: ");

    for (i = 0; i < len; i++) {
        if (isalpha((unsigned char)text[i])) {
            char base = isupper((unsigned char)text[i]) ? 'A' : 'a';

            printf("%c",
                (text[i] - base + key[i]) % 26 + base);
        } else {
            printf("%c", text[i]);
        }
    }

    printf("\n");

    return 0;
}