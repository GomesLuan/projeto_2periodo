#include <stdio.h>
#include <stdlib.h>
#include "telas_locacoes.h"

//Variável provisória
char locacao[3][50] = {"Fantasia do Batman", "9", "90.00"};

void cadastrar_locacao(void) {
    char **info = malloc(3* sizeof(char*));
    for (int i=0; i < 3; ++i) {
        info[i] = malloc(50* sizeof(char));
    }
    info = tela_cadastro_locacao(); 
    //Adição dos dados à lista
    printf("\nContrato realizado com sucesso!\n\n");
    printf("Pressione ENTER para continuar ");
    getchar();
}

void info_locacao(void) {
    //char *nome;
     //Input com o nome de identificação do aluguel
    //Busca das informações do aluguel solicitada
    tela_info_locacao(locacao[0], locacao[1], locacao[2]);
}

void alterar_locacao(void) {
    //char *nome;
    char *novo_valor = malloc(50* sizeof(char));
    char resp = '1';
    //Input com o nome de identificação do aluguel
    //Busca das informações do aluguel solicitada
    while (resp != '0') {
        resp = tela_alterar_locacao(locacao[1], locacao[2], locacao[3]);
        if (resp == '1') {
            printf("\nPor favor informe o novo nome da vestimenta que deseja alugar: ");
            scanf("%s", novo_valor);
            getchar();
            //mudar nome
            printf("\nAlteracao realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        if (resp == '2') {
            printf("\nPor favor informe a nova quantidade de dias que deseja alugar: ");
            scanf("%s", novo_valor);
            getchar();
            //mudar quantidade de dias
            printf("\nAlteracao realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp == '3') {
            printf("\nPor favor informe o novo preco da locacao diaria: ");
            scanf("%s", novo_valor);
            getchar();
            //Alteração do preco da locacao diaria na lista
            printf("\nAlteracao realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp != '0') {
            printf("\nValor invalido!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
    }
}

void remover_locacao(void) {
     //char *nome;
    char resp = '2';
    //Input com o nome de identificação do contrato
    //Busca das informações do contrato solicitado
    resp = tela_remover_locacao(locacao[0], locacao[1], locacao[2]);
    if (resp == '1') {
        printf("\nContrato removida.\n\n");
        //remove contrato da lista
    }
    else if (resp == '2') {
        printf("\nRetornando...\n\n");
    }
    else {
        printf("\nValor invalido!\n\n");
    }
    printf("Pressione ENTER para continuar ");
    getchar();
}