#include <stdio.h>
#include <stdlib.h>

void code_cesar (char * code,int pos)
{
    int i,aux;

    for (i=0; code[i] != '\0'; i++)
    {
        if (code[i] == ' ')
            continue;
        if (code[i]>=65 && code[i]<= 90)
        {
            aux = (int) code[i] + pos;
            if (aux>90)
            {
                aux = 64 + (aux-90);
            }
            code[i]=aux;
        }
        if (code[i]>=97 && code[i]<= 122)
        {
            aux = (int) code[i] + pos;
            if (aux>122)
            {
                aux = 96 + (aux-122);
            }
            code[i]=aux;
        }
    }

    printf("\nA frase codificada e:\n\n%s\n",code);
}

void decode_cesar (char * code,int pos)
{
    int i,aux;

    for (i=0; code[i] != '\0'; i++)
    {
        if (code[i] == ' ')
            continue;
        if (code[i]>=65 && code[i]<= 90)
        {
            aux = (int) code[i] - pos;
            if (aux<65)
            {
                aux = 91 - (65-aux);
            }
            code[i]=aux;
        }
        if (code[i]>=97 && code[i]<= 122)
        {
            aux = (int) code[i] - pos;
            if (aux<97)
            {
                aux = 123 - (97-aux);
            }
            code[i]=aux;
        }
    }

    printf("\nO codigo decodificado e:\n\n%s\n",code);
}

int main()
{
    char code[100];
    int pos,i;

    printf("Informe a operacao desejada: \n\n1- Codificar\n\n2- Decodificar\n\nInforme Outro Comando Para Sair\n\n");
    scanf("%d",&i);

    while(i==1 || i==2)
    {
        system("cls");
        switch(i)
        {
        case 1:
            printf("Informe a frase que deseja codificar e o numero de posicoes:\n");
            scanf(" %[^\n]s",code);
            scanf("%d",&pos);
            code_cesar(code,pos);
            break;

        case 2:
            printf("Informe o codigo que deseja decodificar e o numero de posicoes:\n");
            scanf(" %[^\n]s",code);
            scanf("%d",&pos);
            decode_cesar(code,pos);
            break;

        default:
            printf("Obrigado por utilizar nossos serviços. Obrigado!");
            break;
        }
        printf("\nInforme a operacao desejada: \n1- Codificar\n2- Decodificar\nOutro Comando Para Sair\n");
        scanf("%d",&i);
    }

    return 0;
}
