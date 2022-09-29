
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "geraPermutacao.c"
// ------------------------------------------------------



// ------------------------------------------------------
#define TAM_MAX 100

FILE *entrada;

int totalLinhas = 0;
int value;
int numDeFitas;
int minutosTotais;
int numeroDeMusicas;
int musicas[100];
int tempo[100];
int qtdeMusicas[100];
int vetorAux[100];
int teste[100];

int main()
{

    if ((entrada = fopen("entrada.txt", "r")) == NULL)
        printf("Erro ao abrir o aquivo.\n");
    else
        printf("Arquivo aberto com sucesso.\n");

    fscanf(entrada, "%i", &numDeFitas);

    // loop de fitas
    for (int i = 0; i < numDeFitas; i++)
    {
        fscanf(entrada, "%i", &minutosTotais);
        fscanf(entrada, "%i", &numeroDeMusicas);

        tempo[i] = minutosTotais;
        qtdeMusicas[i] = numeroDeMusicas;

        int aux = numeroDeMusicas * 2;
        int somaMinutos = 0;
        int tempo = 0;
        int cont = -1;

        for (int i = 1; i < aux + 1; i++)
        {
            fscanf(entrada, "%i", &tempo);
            somaMinutos += tempo;
            if (i % 2 == 1)
                somaMinutos = somaMinutos * 60;
            else
            {
                cont += 1;
                musicas[cont] = somaMinutos;
                somaMinutos = 0;
            }
        }
    }
    int percorreLista = -1;
    for (int i = 0; i < numDeFitas; i++)
    {
        percorreLista += 1;
        int var = qtdeMusicas[i] + percorreLista;
        for (percorreLista; percorreLista < var; percorreLista++)
        {
            vetorAux[percorreLista] = musicas[percorreLista];
            teste[percorreLista] = 0;
        }
        
        geraSequencias(vetorAux, teste, qtdeMusicas[i], 0);

    }
    

    // printf("%d", numDeFitas);
    //  printf("\n%d", tamanhoDeFita);
    //   printf("\n%d", numeroDeMusicas,"\n");

    // for (int i = 0; i < numeroDeMusicas; i++)
    //     printf("%i ", musicas[i]);

    // printf("\n");

    // for (int i = 0; i < numDeFitas; i++)
    //     printf("%i ", qtdeMusicas[i]);

    // printf("\n");

    // for (int i = 0; i < numDeFitas; i++)
    //     printf("%i ", tempo[i]);

    // printf("\n");

    fclose(entrada);

    return 0;
}
