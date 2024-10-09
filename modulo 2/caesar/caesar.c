#include <stdio.h>
#include <cs50.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int alfabetoM [] = {65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90}; //maiusculo
int alfabeto [] = {97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122}; //minusculo
string palavra;
char criptoPalavra;
int ci, pi, k;

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "portuguese");
    
    k = atoi(argv[1]);

    // imprime se caso ocorra um erro
    if( argc != 2 || k <=0)
    {
        printf("erro");

        return 1;
    }

    printf("%i", k);

    palavra = get_string("Insira a sua palavra que ir� ser criptografada: ");

    for(int i = 0; i < strlen(palavra); i++)
    {
        if(isalpha(palavra[i]))
        {
            //LETRAS MAIUSCULAS
            if(isupper(palavra[i]))
            {
                pi = (int) palavra[i] - 65;

                ci = (pi + k) % 26;

                printf("%c", alfabetoM[ci]);
            }
            //LETRAS MINUSCULAS 
            else
            {
                pi = (int) palavra[i] - 97;

                ci = (pi + k) % 26;

                printf("%c", palavra[ci]);
            }
        }
        else
        {
            printf("%c", palavra[i]);
        }
    }

    return 0;

}