
#include <stdio.h>
#include <string.h>

int main()
{
    char text[100];
    int key[100], i, n;

    printf("Enter plaintext: ");
    scanf("%s", text);

    n = strlen(text);

    printf("Enter key values:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &key[i]);
    }

    printf("Encrypted text: ");

    for(i = 0; i < n; i++)
    {
        int p = text[i] - 'a';
        int c = (p + key[i]) % 26;

        printf("%c", c + 'a');
    }

    return 0;
}
