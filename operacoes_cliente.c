#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telas_cliente.h"
#include "operacoes_cliente.h"

typedef struct cliente {
    char cpf[12];
    char nome[81];
    char nasc[9];
    char tel[14];
    char email[81];
} Cliente;

void cadastrar_cliente(void) {
    Cliente *cl = (Cliente*) malloc(sizeof(Cliente));
    tela_cadastro_cliente(cl); 
    grava_cliente(cl);
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
    char *cpf = (char*) malloc(12*sizeof(char));
    printf("Informe o cpf do cliente (apenas números): ");
    scanf("%s", cpf);
    getchar();
    Cliente *cl = busca_cliente(cpf);
    if (cl != NULL) {
        tela_info_cliente(cl);
    }
    else {
        printf("\nNão foi encontrado nenhum cliente com este cpf.\n\n");
        printf("Pressione ENTER para continuar ");
        getchar();
    }
    free(cpf);
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
    free(cl);
}

void grava_cliente(Cliente *cl) {
    FILE* arq;
    arq = fopen("clientes.dat", "ab");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo!\n\n");
        printf("Pressione ENTER para continuar ");
        getchar();
    }
    else {
        fwrite(cl, sizeof(Cliente), 1, arq);
    }
    fclose(arq);
}

Cliente *busca_cliente(char *cpf) {
    FILE* arq;
    Cliente *cl = (Cliente*) malloc(sizeof(Cliente));
    arq = fopen("clientes.dat", "rb");
    if (arq == NULL) {
        return NULL;
    }
    else {
        while (!feof(arq)) {
            fread(cl, sizeof(Cliente), 1, arq);
            if (!strcmp(cl->cpf, cpf)) {
                fclose(arq);
                return cl;
            }
        }
    }
    fclose(arq);
    return NULL;
}