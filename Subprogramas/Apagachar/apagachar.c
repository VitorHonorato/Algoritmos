#include <stdio.h>

void apagachar(char * s,char c)
{
    int i,cont=0;

    for (i=0; s[i]!='\0'; i++)
    {
        if (s[i] == c)
        {
            s[i]=' ';
            cont++;
        }
    }
    printf("A frase sem o o caracter desejado e: %s\n",s);
    printf("O numero de caracteres apagados e de: %d\n",cont);
}

int main()
{
    char s[100],c;

    printf("Informe o frase desejada: \n");
    scanf(" %[^\n]s",s);
    printf("Informe o caractere que deseja apagar: \n");
    scanf(" %c",&c);

    apagachar(s,c);

    return 0;
}
