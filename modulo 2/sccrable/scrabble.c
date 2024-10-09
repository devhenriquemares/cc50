#include <locale.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
	setlocale(LC_ALL, "portuguese"); //define a pontuação padrão para portugues

    string word1 = get_string("Palavra do jogador 1: "); 
	string word2 = get_string("Palavra do jogador 2: ");// Solicitar ao usuário duas palavras

    int score1 = compute_score(word1);
	int score2 = compute_score(word2);// Calcular os pontos de cada palavra

    if(score1 > score2)
	{
		printf("Jogador 1 venceu!!!! (%d pontos)", score1);
	}
	else if(score2 > score1)
	{
		printf("Jogador 2 venceu!!!! (%d pontos)", score2);
	}
	else
	{
		printf("Empate. pontos do jogador 1 = %d, pontos do jogador 2 = %d", score1, score2);
	}  // Imprimir o vencedor
}

int compute_score(string word)
{
	int score = 0;
	
    for(int i = 0; i < strlen(word); i++)
	{
		if(islower(word[i]))
		{
			score = score + POINTS[word[i] - 97];
		} // verifica se o caractere é minusculo e subtrai o valor correto
		if(isupper(word[i]))
		{
			score = score + POINTS[word[i] - 65];
		} // verfica se o caractere é maiusculo e subtrai o valor correto
		
	}
	return score;
	
	// Computa e devolve os pontos de cada palavra
}