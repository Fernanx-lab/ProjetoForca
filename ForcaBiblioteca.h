#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

void Forca()
{
    printf("+----------+\n");
    printf("|          |\n");
    printf("|\n");
    printf("|\n");
    printf("|\n");
    printf("|\n");
}

char* AchePalavra(FILE* arquivo, int numeroDoTopico, int numeroDaPalavra)
{
    char linha[100];
    char tagProcurada[20];

    sprintf(tagProcurada, "[T%dP%d]", numeroDoTopico, numeroDaPalavra);

    while (fscanf(arquivo, "%s", linha) != EOF)
    {
        if (strcmp(linha, tagProcurada) == 0)
        {
            if (fscanf(arquivo, "%s", linha) == 1)
            {
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
    }

    return NULL;
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

char* LerPalavras()
{
    FILE* palavras = fopen("C:\\Work\\ProjetoForca\\palavras_forca.txt", "r");

    srand(time(NULL));

    int numeroDoTopico = (rand() % 6) + 1;    
    int numeroDaPalavra = (rand() % 50) + 1;    

    char* palavra = AcheTopico(palavras, numeroDoTopico, numeroDaPalavra);

    fclose(palavras);

    return palavra;
}

int QtdLetras(char* palavra)
{
    int contador = 0;
    while (palavra[contador] != '\0')
    {
        contador++;
    }
    return contador;
}

void TamanhoDaPalavra(char* palavra)
{
    int tamanho = QtdLetras(palavra);
    for(int i = 0; i < tamanho; i++)
    {
        printf("_ ");
    }
}