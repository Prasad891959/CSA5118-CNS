#include <stdio.h>
#include <string.h>

int main() {
    char data[100];
    int block, len, i;

    printf("Enter binary plaintext: ");
    scanf("%99s", data);

    printf("Enter block size: ");
    scanf("%d", &block);

    if (block <= 0) {
        printf("Invalid block size.\n");
        return 1;
    }

    len = strlen(data);

    data[len++] = '1';

    while (len % block != 0)
        data[len++] = '0';

    data[len] = '\0';

    printf("Padded plaintext: %s\n", data);
    printf("Total bits: %d\n", len);

    return 0;
}