/*
Projeto e Análise de Algoritmos II
Professor: Fábio Lubacheski

Projeto 1
Backtracking (Fita Cassete)

Alunos: 
Erick Cauã Ferreira Gomes           | TIA: 32116251
Laura Carolina Balbachan dos Santos | TIA: 32173008

*/

// ------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ------------------------------------------------------
#define TAM_MAX 100

FILE *entrada;

int totalLinhas = 0; 
char dadosArquivo[TAM_MAX][TAM_MAX];

// ------------------------------------------------------
void somaMusicas(int musica1, int musica2);
void leituraRegras(char listaDados[]);
// ------------------------------------------------------


int main() {

    if((entrada = fopen("entrada.txt", "r")) == NULL)
        printf("Erro ao abrir o aquivo.\n");
    else
      printf("Arquivo aberto com sucesso.\n");  


    while(!feof(entrada))
        if (fgets(dadosArquivo[totalLinhas], TAM_MAX, entrada) != NULL){
            totalLinhas++;
    }

    fclose(entrada);

    for(int i = 0; i <totalLinhas; i++)
        printf("%s", dadosArquivo[i]);

    printf("\n\nLinha que precisamoooos: %s", dadosArquivo[1]);

    return 0;
}
