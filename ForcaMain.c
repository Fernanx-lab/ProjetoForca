#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

int main() {
    int opcao;
    FILE *arquivo;
    char linha[256];

    arquivo = fopen("Opcoes_jogo_da_forca.txt", "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha); 
    }
    
    fclose(arquivo);

    do {
        printf("\n| BEM VINDO AO JOGO DA FORCA:\n");
        Opcoes_Jogo();
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:

            break;

            default:
            printf("Opcao invalida. Por favor, tente novamente.\n");
        }
    } while(opcao != 0);

return 0;
}