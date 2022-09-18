#include <stdio.h>
#include <stdlib.h>
#include "telas_vestimenta.h"

void cadastrar_vestimenta(void) {
    char **info = malloc(5* sizeof(char*));
    for (int i=0; i < 5; ++i) {
        info[i] = malloc(50* sizeof(char));
    }
    info = tela_cadastro_vestimenta(); 
    //Adição dos dados à lista
    printf("\nCadastro realizado com sucesso!\n\n");
    printf("Pressione ENTER para continuar ");
    getchar();
}