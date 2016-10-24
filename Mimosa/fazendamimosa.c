//   Vitor Honorato da Silva      Turma: CC

#include <stdio.h>
#include <stdlib.h>
#define NOMEARQUIVO "ficha_gados.bin"

struct data
{
    int mes,ano;
};

struct ficha_gado
{
    int cod;
    float qtde_litros;
    float qtde_alimento;
    struct data data_nasc;
    char abate;
};

struct ficha_gado gados[2000];
int aux = 0;

FILE * abre_arq(char[],char[]);
void carrega_dados(void);
void leite_total(void);
void alim_total(void);
void leite_abate(void);
void num_abate(void);
void novo_registro(void);
void lista_registro(void);

int main()
{
    char op;

    do
    {
        printf("Menu:\n");
        printf("1 - Carregar dados do arquivo:\n");
        printf("2 - Total de leite produzido:\n");
        printf("3 - Total de alimento consumido:\n");
        printf("4 - Total de leite produzido apos o abate:\n");
        printf("5 - Numero de cabecas que vao para o abate:\n");
        printf("6 - Incluir novo registro:\n");
        printf("7 - Listar registros:\n");
        printf("8 - Sair do programa:\n");

        op = getche();
        system("cls");

        switch(op)
        {
        case '1':
            carrega_dados();
            break;
        case '2':
            leite_total();
            break;
        case '3':
            alim_total();
            break;
        case '4':
            leite_abate();
            break;
        case '5':
            num_abate();
            break;
        case '6':
            novo_registro();
            break;
        case '7':
            lista_registro();
            break;
        }
    }
    while(op != '8');
    return 0;
}

FILE* abre_arq(char nome[],char modo[])
{
    FILE *arq;

    if((arq = fopen(nome,modo)) == NULL)
    {
        printf("Erro ao abrir o arquivo <%s>",nome);
        return NULL;
    }

    return arq;
}

void carrega_dados()
{
    int cont = 0;
    FILE *file = abre_arq(NOMEARQUIVO,"rb");
    aux = fread(&gados[0], sizeof(struct ficha_gado), 2000, file);
    fclose(file);
    printf("Dados carregados com sucesso!\n\n");
}

void leite_total()
{
    float soma_leite = 0;
    int i;

    for (i = 0; i < 2000; i++)
    {
        soma_leite += gados[i].qtde_litros;
    }

    printf("Total de leite produzido por semana: %.2f litros\n\n", soma_leite);
}

void alim_total()
{
    float soma_alim = 0;
    int i;

    for (i = 0; i < 2000; i++)
    {
        soma_alim += gados[i].qtde_alimento;
    }

    printf("Total de alimento consumido por semana: %.2f kg\n\n", soma_alim);
}

void leite_abate()
{
    float soma_leite = 0;
    int i;

    for (i = 0; i < 2000; i++)
    {
        if (gados[i].abate == 'N')
        {
            soma_leite += gados[i].qtde_litros;
        }
    }

    printf("Total de leite produzido por semana apos abate: %.2f litros\n\n", soma_leite);
}

void num_abate()
{
    int i, cont = 0;

    for (i = 0; i < 2000; i++)
    {
        if (gados[i].abate == 'S')
        {
            cont ++;
        }
    }

    printf("Total de cabecas que vao para o abate: %d cabecas\n\n", cont);
}

void novo_registro()
{
    carrega_dados();
    int cont, idade, meses = 12 * 2016 + 10;
    char dec, ch;
    cont = aux;
    FILE *file = abre_arq(NOMEARQUIVO,"wb");
    if (aux >= 2000)
    {
        printf("Voce ja registrou 2000 gados!! Impossivel registrar mais!!");
    }
    else
    {
        do
        {
            gados[cont].cod = cont;
            printf("Informe a quantidade de litros produzido: ");
            scanf("%f",&gados[cont].qtde_litros);
            printf("Informe a quantidade de alimento consumido: ");
            scanf("%f",&gados[cont].qtde_alimento);
            printf("Informe o nascimento do gado (mes/ano): ");
            scanf("%d%c%d",&gados[cont].data_nasc.mes, &ch, &gados[cont].data_nasc.ano);

            idade =  meses - (gados[cont].data_nasc.mes + gados[cont].data_nasc.ano * 12);

            if (idade > 60 || gados[cont].qtde_litros < 40 || (gados[cont].qtde_litros >= 50 && gados[cont].qtde_litros <= 70 && gados[cont].qtde_alimento > 50))
            {
                gados[cont].abate = 'S';
            }
            else
            {
                gados[cont].abate = 'N';
            }

            printf("\nDeseja incluir outro registro?\nS para sim\nN para nao\n");
            dec = getche();
            cont++;
            printf("\n\n");
        }
        while(dec == 'S' || dec == 's');
    }
    fwrite(&gados[0],sizeof(struct ficha_gado),cont,file);
    aux = cont;
    fclose(file);
}

void lista_registro()
{
    int cont;

    for (cont = 0; cont < aux; cont++)
    {
        printf("Codigo do gado: %d\n", gados[cont].cod);
        printf("Quantidade de leite produzido: %.2f litros\n", gados[cont].qtde_litros);
        printf("Quantidade de alimento consumido: %.2f kg\n", gados[cont].qtde_alimento);
        printf("Data de nascimento do gado: %d/%d\n", gados[cont].data_nasc.mes, gados[cont].data_nasc.ano);
        printf("Gado vai para o abate? : %c\n\n", gados[cont].abate);
    }
}
