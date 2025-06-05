#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

char* LerPalavras()
{
    FILE* palavras = fopen("palavras_forca_corrigido.txt", "r");

    srand(time(NULL));

    int numeroDoTopico = (rand() % 6) + 1;  
    int numeroDaPalavra = (rand() % 50) + 1; 

    char* palavra = AcheTopico(palavras, numeroDoTopico, numeroDaPalavra);

    fclose(palavras);

    return palavra; 
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

char* AcheTopico(FILE* arquivo, int numeroDoTopico, int numeroDaPalavra)
{
    char linha[100];
    char tagProcurada[10];

    sprintf(tagProcurada, "[T%d]", numeroDoTopico);

    rewind(arquivo);

    while (fscanf(arquivo, "%s", linha) != EOF)
    {
        if (strcmp(linha, tagProcurada) == 0)
        {
            return AchePalavra(arquivo, numeroDoTopico, numeroDaPalavra);
        }
    }

    return NULL;
}

char* AchePalavra(FILE* arquivo, int numeroDoTopico, int numeroDaPalavra)
{
    char linha[100];
    char tagProcurada[20];

    sprintf(tagProcurada, "[T%dP%d]", numeroDoTopico, numeroDaPalavra);

    rewind(arquivo);

    while (fscanf(arquivo, "%s", linha) != EOF)
    {
        if (strcmp(linha, tagProcurada) == 0)
        {
            fscanf(arquivo, "%s", linha);

            char* palavra = malloc(strlen(linha) + 1);
            if (palavra == NULL)
            {
                printf("Erro de memoria.\n");
                exit(1);
            }
            strcpy(palavra, linha);
            return palavra;
        }
    }

    return NULL;
}