#include <stdio.h>
#include "ForcaBiblioteca.h" 

int main() {
Forca();
char palavra[100] = LerPalavras();
int x = QtdLetras(palavra);
printf("Quantidade de letras: %d\n", x);
TamanhoDaPalavra(palavra);

return 0;
}