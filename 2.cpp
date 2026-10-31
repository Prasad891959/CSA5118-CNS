
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[100];
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int i, pos;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    for(i = 0; text[i] != '\0'; i++)
    {
        if(isupper(text[i]))
        {
            pos = text[i] - 'A';
            text[i] = key[pos];
        }
        else if(islower(text[i]))
        {
            pos = text[i] - 'a';
            text[i] = tolower(key[pos]);
        }
    }

    printf("Encrypted text: %s", text);

    return 0;
}
