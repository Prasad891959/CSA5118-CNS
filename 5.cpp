
#include <stdio.h>
#include <ctype.h>

int main()
{
    char text[100];
    int a, b, i, p, c;

    printf("Enter plaintext: ");
    scanf("%s", text);

    printf("Enter a value: ");
    scanf("%d", &a);

    printf("Enter b value: ");
    scanf("%d", &b);

    printf("Encrypted text: ");

    for(i = 0; text[i] != '\0'; i++)
    {
        p = toupper(text[i]) - 'A';

        c = (a * p + b) % 26;

        printf("%c", c + 'A');
    }

    return 0;
}
