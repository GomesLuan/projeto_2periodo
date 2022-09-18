#include <stdio.h>
#include <stdlib.h>
#include "telas_vestimenta.h"

//Variável provisória
char vestimenta[5][50] = {"Fantasia do Batman", "3", "2", "5", "90.00"};

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

void info_vestimenta(void) {
    //char *nome;
    //Input com o nome de identificação da vestimenta
    //Busca das informações da vestimenta solicitada
    tela_info_vestimenta(vestimenta[0], vestimenta[1], vestimenta[2], vestimenta[3], vestimenta[4]);
}