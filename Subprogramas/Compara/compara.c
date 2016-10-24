#include <stdio.h>
#include <string.h>

int compara(char * s1, char * s2)
{
    int i,j=0,pos,aux;

    aux = strlen(s2);

    for (i=0; s1[i] != '\0'; i++)
    {
        if (s1[i] == s2[j])
        {
            j++;
            if (j==1)
            {
                pos = i;
            }
        }
        else
        {
            j=0;
        }
        if (j==aux) break;
    }
    if (j==aux) return pos;
    else return -1;
}

int main()
{
    char s1[100],s2[100];
    int pos;

    printf("Informe a frase desejada: \n");
    scanf(" %[^\n]s",s1);

    printf("Informe a frase que deseja comparar: \n");
    scanf(" %[^\n]s",s2);

    if (compara(s1,s2)==-1) printf("A s2 nao existe em s1 \n");
    else printf("A s2 se encontra na s1 a partir da posicao %d\n",compara(s1,s2));

    return 0;
}
