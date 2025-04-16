#include "baralho.h"
#include <stdlib.h>

carta * criar_baralho()
{
  carta * baralho = (carta *) malloc(sizeof(carta) * 52);
  preencher_baralho(baralho, 'P');
  preencher_baralho(baralho, 'C');
  preencher_baralho(baralho, 'E');
  preencher_baralho(baralho, 'O');
}

void preencher_baralho(carta * baralho, char naipe)
{
  for(int i = 0; i < 13; i++)
  {
    baralho[i].numero = i + 1;
    baralho[i].naipe = naipe;
  }
}

void embaralhar(carta * baralho, int n)
{
  for(int k = 0; k < 0.6 * n; k++)
  {
    int i = rand() % n;
    int j = rand() % n;
    carta c = baralho[i];
    baralho[i] = baralho[j];
    baralho[j] = c;
  }
}