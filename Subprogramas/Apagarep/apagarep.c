#include <stdio.h>

void apagarep(char * s)
{
    int i,j;
    char c;

    for (i=0; s[i]!= '\0'; i++)
    {
        if (s[i]==' ') continue;
        c=s[i];
        for (j=i+1; s[j]!= '\0'; j++)
        {
            if (s[j]==c)
            {
                s[j]=' ';
            }
        }
    }

    printf("A frase sem os caracteres repitidos e: %s\n",s);
}

int main()
{
    char s[100];

    printf("Informe o frase desejada: \n");
    scanf(" %[^\n]s",s);

    apagarep(s);

    return 0;
}
