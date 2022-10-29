#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telas_cliente.h"

void cadastrar_cliente(void) {
    Cliente *cl = (Cliente*) malloc(sizeof(Cliente));
    tela_cadastro_cliente(cl); 
    //Adição dos dados em arquivo
    printf("\nCadastro realizado com sucesso!\n\n");
    printf("CPF: %s\n", cl->cpf);
    printf("Nome: %s\n", cl->nome);
    printf("Data de nascimento: %s\n", cl->nasc);
    printf("Telefone: %s\n", cl->tel);
    printf("E-Mail: %s\n\n", cl->email);
    printf("Pressione ENTER para continuar ");
    getchar();
    free(cl);
}

void info_cliente(void) {
    //char *cpf;
    //Input com o cpf do cliente
    //Busca das informações do cliente solicitado
    Cliente *cl = (Cliente*) malloc(sizeof(Cliente));
    strcpy(cl->cpf, "12345678909");
    strcpy(cl->nome, "Fulano da Silva");
    strcpy(cl->nasc, "01012001");
    strcpy(cl->tel, "99999999");
    strcpy(cl->email, "fulano@gmail.com");
    tela_info_cliente(cl);
    free(cl);
}

void alterar_cliente(void) {
    //char *cpf;
    char resp = '1';
    //Input com o cpf do cliente
    //Busca das informações do cliente solicitado
    Cliente *cl = (Cliente*) malloc(sizeof(Cliente));
    strcpy(cl->cpf, "12345678909");
    strcpy(cl->nome, "Fulano da Silva");
    strcpy(cl->nasc, "01012001");
    strcpy(cl->tel, "99999999");
    strcpy(cl->email, "fulano@gmail.com");
    while (resp != '0') {
        resp = tela_alterar_cliente(cl);
        if (resp == '1') {
            cad_nome_cliente(cl->nome);
            //Alteração do nome no arquivo
            printf("\nAlteração realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp == '2') {
            cad_nasc_cliente(cl->nasc);
            //Alteração da data de nascimento no arquivo
            printf("\nAlteração realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp == '3') {
            cad_tel_cliente(cl->tel);
            //Alteração do telefone no arquivo
            printf("\nAlteração realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp == '4') {
            cad_email_cliente(cl->email);
            //Alteração do e-mail no arquivo
            printf("\nAlteração realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp != '0') {
            printf("\nValor inválido!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
    }
    free(cl);
}

void remover_cliente(void) {
    //char *cpf;
    char resp = '2';
    //Input com o cpf do cliente
    //Busca das informações do cliente solicitado
    Cliente *cl = (Cliente*) malloc(sizeof(Cliente));
    strcpy(cl->cpf, "12345678909");
    strcpy(cl->nome, "Fulano da Silva");
    strcpy(cl->nasc, "01012001");
    strcpy(cl->tel, "99999999");
    strcpy(cl->email, "fulano@gmail.com");
    resp = tela_remover_cliente(cl);
    free(cl);
    if (resp == '1') {
        printf("\nCliente removido.\n\n");
        //remove cliente do arquivo
    }
    else if (resp == '2') {
        printf("\nRetornando...\n\n");
    }
    else {
        printf("\nValor inválido!\n\n");
    }
    printf("Pressione ENTER para continuar ");
    getchar();
}