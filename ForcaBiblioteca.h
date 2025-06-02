#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

void LerPalavras()
{
    FILE* palavras = fopen("palavras_forca.txt", "R");
    srand(time(NULL));
    int numeroDoTopico = rand() % 5;
    int numeroDaPalavra = rand() % 50;

}

void Forca()
{
    printf("+----------+\n");
    printf("|          |\n");
    printf("|\n");
    printf("|\n");
    printf("|\n");
    printf("|\n");
}

bool AcheTopico(FILE* arquivo, int numeroDoTopico)
{
    char linha[100];
    char tagProcurada[10];

    sprintf(tagProcurada, "[T%d]", numeroDoTopico);

    rewind(arquivo);

    while (fscanf(arquivo, "%s", linha) != EOF)
    {
        if (strcmp(linha, tagProcurada) == 0)
        {
            return true; 
        }
    }

    return false; 
}
