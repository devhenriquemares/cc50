#include <stdio.h>
#include <cs50.h>
#include <locale.h>

int linha, col, espace, altura;

int main(void)
{
    do
    {
        altura = get_int("Insira a altura da piramide: ");
    }
    while(altura <= 0 || altura > 80);

    for(linha = 0; linha < altura; linha++)
    {
        for(espace = 0; espace < (altura - (linha + 1)); espace++)
        {
            printf(" ");
        }
        for(col = 0; col <= linha; col++)
        {
            printf("#");
        }
        printf(" ");
        for (col = 0; col <= linha; col++)
        {
            printf("#");
        }
        
        printf("\n");
    }
    
}