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
    char status;
    Cliente *prox;
} Cliente;

void cadastrar_cliente(void) {
    Cliente *cl = (Cliente*) malloc(sizeof(Cliente));
    tela_cadastro_cliente(cl); 
    cl->status = 'c';
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
    printf("\nInforme o cpf do cliente (apenas números): ");
    scanf("%s", cpf);
    getchar();
    Cliente *cl = busca_cliente(cpf, 0);
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
    char resp = '1';
    char *cpf = (char*) malloc(12*sizeof(char));
    printf("\nInforme o cpf do cliente (apenas números): ");
    scanf("%s", cpf);
    getchar();
    Cliente *cl = busca_cliente(cpf, 0);
    if (cl != NULL) {
        while (resp != '0') {
            resp = tela_alterar_cliente(cl);
            if (resp == '1') {
                cad_nome_cliente(cl->nome);
                edita_cliente(cl);
                printf("\nAlteração realizada com sucesso!\n\n");
                printf("Pressione ENTER para continuar ");
                getchar();
            }
            else if (resp == '2') {
                cad_nasc_cliente(cl->nasc);
                edita_cliente(cl);
                printf("\nAlteração realizada com sucesso!\n\n");
                printf("Pressione ENTER para continuar ");
                getchar();
            }
            else if (resp == '3') {
                cad_tel_cliente(cl->tel);
                edita_cliente(cl);
                printf("\nAlteração realizada com sucesso!\n\n");
                printf("Pressione ENTER para continuar ");
                getchar();
            }
            else if (resp == '4') {
                cad_email_cliente(cl->email);
                edita_cliente(cl);
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
    }
    else {
        printf("\nCliente não encontrado!\n\n");
        printf("Pressione ENTER para continuar ");
        getchar();
    }
    free(cl);
    free(cpf);
}

void remover_cliente(void) {
    char resp = '2';
    char *cpf = (char*) malloc(12*sizeof(char));
    printf("\nInforme o cpf do cliente (apenas números): ");
    scanf("%s", cpf);
    getchar();
    Cliente *cl = busca_cliente(cpf, 0);
    if (cl != NULL) {
        resp = tela_remover_cliente(cl);
        if (resp == '1') {
            printf("\nCliente removido.\n\n");
            exclui_cliente(cpf);
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
    else {
        printf("\nCliente não encontrado!\n\n");
        printf("Pressione ENTER para continuar ");
        getchar();
    }
    free(cl);
    free(cpf);
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

Cliente *busca_cliente(char *cpf, int inclui_excluido) {
    FILE* arq;
    Cliente *cl = (Cliente*) malloc(sizeof(Cliente));
    arq = fopen("clientes.dat", "rb");
    if (arq == NULL) {
        fclose(arq);
        return NULL;
    }
    else {
        while (!feof(arq)) {
            fread(cl, sizeof(Cliente), 1, arq);
            if (!strcmp(cl->cpf, cpf) && (cl->status != 'x' || inclui_excluido)) {
                fclose(arq);
                return cl;
            }
        }
    }
    fclose(arq);
    return NULL;
}

void edita_cliente(Cliente *cl_lido) {
    FILE* arq;
    Cliente *cl_arq = (Cliente*) malloc(sizeof(Cliente));
    arq = fopen("clientes.dat", "r+b");
    int encontrado = 0;
    if (arq == NULL) {
        printf("Erro ao abrir arquivo!\n\n");
        printf("Pressione ENTER para continuar ");
        getchar();
    }
    while (!feof(arq)) {
        fread(cl_arq, sizeof(Cliente), 1, arq);
        if (!strcmp(cl_lido->cpf, cl_arq->cpf) && cl_arq->status != 'x') {
            encontrado = 1;
            fseek(arq, -1*sizeof(Cliente), SEEK_CUR);
            fwrite(cl_lido, sizeof(Cliente), 1, arq);
            fclose(arq);
            free(cl_arq);
            break;
        }
    }
    fclose(arq);
    free(cl_arq);
    if (!encontrado) {
        printf("Cliente não encontrado!\n\n");
        printf("Pressione ENTER para continuar ");
        getchar();
    }
}

void exclui_cliente(char *cpf) {
    FILE* arq;
    Cliente *cl = (Cliente*) malloc(sizeof(Cliente));
    arq = fopen("clientes.dat", "r+b");
    int encontrado = 0;
    if (arq == NULL) {
        printf("Erro ao abrir arquivo!\n\n");
        printf("Pressione ENTER para continuar ");
        getchar();
    }
    while (!feof(arq)) {
        fread(cl, sizeof(Cliente), 1, arq);
        if (!strcmp(cpf, cl->cpf) && cl->status != 'x') {
            encontrado = 1;
            cl->status = 'x';
            fseek(arq, -1*sizeof(Cliente), SEEK_CUR);
            fwrite(cl, sizeof(Cliente), 1, arq);
            fclose(arq);
            free(cl);
            break;
        }
    }
    fclose(arq);
    free(cl);
    if (!encontrado) {
        printf("Cliente não encontrado!\n\n");
        printf("Pressione ENTER para continuar ");
        getchar();
    }
}