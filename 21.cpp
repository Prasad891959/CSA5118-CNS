#include <stdio.h>
#include <string.h>

int main() {
    char data[100];
    int i, len, block;

    printf("Enter binary data: ");
    scanf("%99s", data);

    printf("Enter block size: ");
    scanf("%d", &block);

    len = strlen(data);

    data[len++] = '1';

    while (len % block != 0)
        data[len++] = '0';

    data[len] = '\0';

    printf("Padded data: %s\n", data);
    printf("Padded length: %d bits\n", len);

    return 0;
}