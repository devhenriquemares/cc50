#include <stdio.h>
#include <cs50.h>

const int num_cartao;
int t;

void multi(void);

void main (void)
{

    const int num_cartao = get_int("teste: ");

    multi();

    printf("%d", t);

}

void multi(void)
{   
    main();

    t = num_cartao*2;
}