#include <stdio.h>

int main()
{
    char str[256];
    int k = 0,
        len = 0;
    gets(str);
    scanf_s("%d", &k);
    len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] < 91 && str[i] > 64)
        {
            str[i] = (str[i] - 65 + k) % 27 + 65;
        }
        else if (str[i] > 96 && str[i] < 123)
        {
            str[i] = (str[i] - 97 + k) % 27 + 97;

        }
        printf("%c", str[i]);
    }

    return 0;
}