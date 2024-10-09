#include <stdio.h>  
#include <cs50.h>
#include <locale.h>

void main(void)
{   
    setlocale(LC_ALL, "portuguese");

    int n = get_int("quantidade de notas: \n"); 
    
    int nota[n]; 

    int quantidade; 

    for(quantidade = 0; quantidade<=(n - 1); quantidade++)
    {
        nota[quantidade] = get_int("insira a %dº nota: \n", quantidade + 1);
    }

    // int x = 0;

    // do
    // {
    //     if(x<(n-1))
    //     {
    //         printf("%d, ", nota[x]);
    //     }
    //     else
    //     {
    //         printf("%d ", nota[x]);
    //     }

    //     x++;
    // }
    // while(x<=(n-1));

    int soma = 0;

    for(int i = 0; i < quantidade; i++)
    {
        soma = soma + nota[i];
    }

    printf("A média do aluno é %d.", soma / quantidade);

}

