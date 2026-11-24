
#include <stdio.h>

int main() {
    char text[500];
    int count[26] = {0};
    int i;

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            count[text[i] - 'A']++;
        else if (text[i] >= 'a' && text[i] <= 'z')
            count[text[i] - 'a']++;
    }

    printf("\nFrequency Analysis:\n");

    for (i = 0; i < 26; i++) {
        printf("%c = %d\n", 'A' + i, count[i]);
    }

    printf("\nEnglish frequency order: ETAOINSHRDLCUMWFGYPBVKJXQZ\n");

    return 0;
}
