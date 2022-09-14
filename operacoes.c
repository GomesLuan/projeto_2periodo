#include <stdio.h>
#include <stdlib.h>
#include "telas.h"
#include "op_sistema.h"

//Variável provisória
char cliente[5][50] = {"Fulano da Silva", "12345678909", "01/01/2000", "99999-9999", "fulano@gmail.com"};

void cadastrar_cliente(void) {
    char **info = malloc(5* sizeof(char*));
    for (int i=0; i < 5; ++i) {
        info[i] = malloc(50* sizeof(char));
    }
    info = tela_cadastro_cliente(); 
    //Adição dos dados à lista
    printf("\nCadastro realizado com sucesso!\n\n");
    pausar_sistema();
}

void info_cliente(void) {
    //char *cpf;
    //Input com o cpf do cliente
    //Busca das informações do cliente solicitado
    tela_info_cliente(cliente[0], cliente[1], cliente[2], cliente[3], cliente[4]);
}

void alterar_cliente() {
    //char *cpf;
    char *novo_valor = malloc(50* sizeof(char));
    char resp = '1';
    //Input com o cpf do cliente
    //Busca das informações do cliente solicitado
    while (resp != '0') {
        resp = tela_alterar_cliente(cliente[0], cliente[2], cliente[3], cliente[4]);
        if (resp == '1') {
            printf("\nPor favor informe o novo nome: ");
            scanf("%s", novo_valor);
            getchar();
            //Alteração do nome na lista
            printf("\nAlteracao realizada com sucesso!\n\n");
        }
        else if (resp == '2') {
            printf("\nPor favor informe a nova data de nascimento: ");
            scanf("%s", novo_valor);
            getchar();
            //Alteração da data de nascimento na lista
            printf("\nAlteracao realizada com sucesso!\n\n");
        }
        else if (resp == '3') {
            printf("\nPor favor informe o novo telefone: ");
            scanf("%s", novo_valor);
            getchar();
            //Alteração do telefone na lista
            printf("\nAlteracao realizada com sucesso!\n\n");
        }
        else if (resp == '4') {
            printf("\nPor favor informe o novo e-mail: ");
            scanf("%s", novo_valor);
            getchar();
            //Alteração do e-mail na lista
            printf("\nAlteracao realizada com sucesso!\n\n");
        }
        else if (resp != '0') {
            printf("\nValor invalido!\n\n");
        }
        pausar_sistema();
    }
}

void remover_cliente() {
    //char *cpf;
    char resp = '2';
    //Input com o cpf do cliente
    //Busca das informações do cliente solicitado
    resp = tela_remover_cliente(cliente[0], cliente[1], cliente[2], cliente[3], cliente[4]);
    if (resp == '1') {
        printf("\nCliente removido.\n\n");
        //remove cliente da lista
    }
    else if (resp == '2') {
        printf("\nRetornando...\n\n");
    }
    else {
        printf("\nValor invalido!\n\n");
    }
    pausar_sistema();
}