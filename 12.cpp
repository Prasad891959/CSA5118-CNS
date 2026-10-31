
#include <stdio.h>
#include <string.h>

int main()
{
    char text[100];
    int key[2][2] = {{9, 4}, {5, 7}};
    int p, q, c1, c2, i;

    printf("Enter plaintext (2 letters): ");
    scanf("%s", text);

    p = text[0] - 'a';
    q = text[1] - 'a';

    c1 = (key[0][0]*p + key[0][1]*q) % 26;
    c2 = (key[1][0]*p + key[1][1]*q) % 26;

    printf("Encrypted text: ");
    printf("%c%c\n", c1+'a', c2+'a');

    return 0;
}
