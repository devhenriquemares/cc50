#include <cs50.h>
#include <stdio.h>
#include <string.h>

// define o numero maximo de candidatos
#define MAX 9

// cria uma estrutura "typedef" define o tipo, "struct" define que o tipo é estrutura
typedef struct
{
    string name; //essa estrutura recebe uma string chamada "name"

    int votes; //e tambem recebe um int chamado "votes"

} candidate; // aq a estrutura recebe o nome dela

//array com nome candidatos, cria varias estruturas cada candidato recebe sua propria estrutura
candidate candidates[MAX];

// numero de candidatos
int candidate_count;

// prototipos de funções
bool vote(string name);
void print_winner(void);

//função principal
int main(int argc, string argv[])
{
    // verifica se a quantidade minima esta sendo atendida
    if (argc < 3)
    {
        printf("Insira o nome de pelo menos dois candidatos...\n");

        return 1;
    }

    // verifica se a quantidade maxima esta sendo quebrada
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("O número maximo de candidatos é %i\n", MAX);

        return 2;
    }

    //define o nome e quantidade de votos de cada estrutura para cada candidato
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1]; //define que o nome do candidato[0] sera o nome inserido logo apos o ./main, e assim por diante

        candidates[i].votes = 0; //define que o valor inicial de votos é zero
    }

    int voter_count = get_int("Numero de votos: "); //variavel de votos


    // loop de todos os eleitores
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Voto invalido.\n");

            i--;
        }
    }

    // printa o(s) nome(s) do(s) candidato(s) vencedor(es)
    print_winner();
}

// devolve um valor falso caso o nome escrito em "voto" nao exista
bool vote(string name)
{
    for(int i = 0; i < candidate_count; i++)
    {
        if(strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes ++;

            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int maxvotes = 0;

    for(int i = 0; i < candidate_count; i++)
    {
        if(candidates[i].votes > maxvotes)
        {
            maxvotes = candidates[i].votes;
        }
    }

    for(int i = 0; i < candidate_count; i++)
    {
        if(candidates[i].votes == maxvotes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}