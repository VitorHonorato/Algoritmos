#include <stdio.h>
#include <string.h>

void sorteio (char * s, int sor)
{
    int i,x,j;

    j = strlen(s);

    srand( (unsigned)time(NULL) );

    for (i=1; i<=sor; i++)
    {
        x = rand() % j;

        if (s[x]==' ') continue;

        if (s[x]>=65 && s[x]<=90)
        {
            s[x]=(int) s[x] + 32;
        }

        if (s[x]>=97 && s[x]<=122)
        {
            s[x]=(int) s[x] - 32;
        }
    }

    printf("%s",s);
}

int main()
{
    int sor;
    char str[100];

    scanf("%[^\n]s",str);
    scanf("%d",&sor);

    sorteio(str,sor);

    return 0;
}
