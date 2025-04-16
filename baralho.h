#define BARALHO_H

#include <stdlib.h>

typedef struct {
  int numero;
  char naipe;
} carta;

carta * criar_baralho();

void preencher_baralho(carta * baralho, char naipe);

void embaralhar(carta * baralho, int n);