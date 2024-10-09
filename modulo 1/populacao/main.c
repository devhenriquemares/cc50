#include <locale.h>
#include <stdio.h>
#include <cs50.h>

int inicio, fim, anos;

int calculo(void);
void dados(void);


int main(void)
{   
    setlocale(LC_ALL, "portuguese");

    dados();
    
    calculo();
    
    if(anos<1)
    {
        printf("São necessários menos de um ano para chegar a essa população");
    }
    else
    {
        printf("São necessários %d anos para a população chegar a esse número.", anos);
    }
}

void dados(void)
{
    do
    {
        inicio = get_int("inicio: \n\n");
        if(inicio<9)
        {
            printf("Tamanho mínimo = 9\n\n");
        }
        else
        {
            do
            {
                fim = get_int("fim : \n\n");
                if(fim<=inicio)
                {
                    printf("tamanho errado\n\n");
                }
            }
            while(fim<=inicio);
        }
    }
    while(inicio<9);    
}

int calculo(void)
{
    do
    {
        inicio = (inicio + inicio / 3) - inicio /4;
        anos++;
    }
    while(inicio < fim);
}