#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

signed main() {
  char ch='s', secreto, resp;
  int tentativas=1;
  while(ch=='s'){
    secreto = rand() % 26 + 'a';
    printf("\n\nDigite uma letra entre 'a' e 'z':\n");
    while((resp=getch())!=secreto){
      printf("%c eh incorreto. Tente novamente\n", resp);
      tentativas++;
    }
    printf("%c EH CORRETO!!\n", resp);
    printf("Voce acertou em %d tentativas\n", tentativas);
    printf("\nQuer jogar novamente? (s/n): ");
    ch=getche();
  }
  return 0;
}