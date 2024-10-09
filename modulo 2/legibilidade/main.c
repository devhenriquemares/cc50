#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

//variaveis
int palavras, frases, letras;

// declara��o de fun��o
int palavrasFunc(string text);
int frasesFunc(string text);
int letrasFunc(string text);

int main(void)
{
    setlocale(LC_ALL, "portuguese"); //define pontua��o padr�o para portugu�s

    string texto = get_string("Insira um texto: \n");

    palavrasFunc(texto);
    frasesFunc(texto);
    letrasFunc(texto);

    float l = ((float)letras / ((float) palavras * 10) * 1000), s = ((float)frases / ((float) palavras * 10) * 1000);

    float indice = 0.0588 * (float) l - 0.296 * (float) s - 15.8;

    int indiceF = round(indice);

    if(indiceF > 16)
    {
        printf("Grau 16+\n");
    }
    else if(indiceF < 1)
    {
        printf("Grau menor que 1\n");
    }
    else 
    {
        printf("Grau de leiturabilidade: %i \n", indiceF);
    }


    printf("quantidade de letras = %i \n Quantidade de frases = %i \n Quantidade de palavras = %i \n", letras, frases, palavras);

}

//fun��o que calcula quantidade de letras
int letrasFunc(string text)
{
    for(int i = 0; i <= strlen(text); i++)
    {
        if(isalpha(text[i]))
        {
            letras += 1;
        }
        else if( (unsigned char) text[i] >= 127)
        {
            letras += 1;
        }
    }

    return letras;
}

//fun��o para calculas a quantidade de frases
int frasesFunc(string text)
{
    for(int i = 0; i < strlen(text); i++)
    {
        if(ispunct(text[i]) && (int) text[i] != 34 && (int) text[i] != 39 && (int) text[i] != 40 && (int) text[i] != 41 && (int) text[i] != 44 && (int) text[i] != 45)
        {   
            if((unsigned char) text[i] <= 127)
            {
                frases += 1;
            }
        }
    }

    return frases;
}

//fun��o para calcular quantidade de palavras
int palavrasFunc(string text)
{
    int espacos = 0;

    for(int i = 0; i < strlen(text); i++)
    {
        if(isspace(text[i]))
        {
            espacos += 1;
        }
    }

    palavras = espacos + 1;

    return palavras;
}