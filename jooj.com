
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ------------------------------------------------------
#define TAM_MAX 100

FILE *entrada;

int totalLinhas = 0; 
int value;
int i;
int main(){

    if((entrada = fopen("entrada.txt", "r")) == NULL)
        printf("Erro ao abrir o aquivo.\n");
    else
      printf("Arquivo aberto com sucesso.\n");  


    for (i=0; i<10; i++){
    fscanf (entrada, "%i", &value) ;
    printf ("%d: %i\n", i, value) ;
  }

    fclose(entrada);

return 0;

}
