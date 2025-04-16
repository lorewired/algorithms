#include <stdio.h>

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

int main() {
  int n;
  scanf("%d", &n);
  int aux = -1, um = 0, dois = 0, tres = 0;
  while(aux != 0) {
    aux = n % 10;
    n /= 10;
    if(aux == 1) um++;
    if(aux == 2) dois++;
    if(aux == 3) tres++;
  }
  if(um == 1 && dois == 2 && tres == 3) {
    printf("Sim\n");
  } else {
    printf("Nao\n");
  }
  return 0;
}