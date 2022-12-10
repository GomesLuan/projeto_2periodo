#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telas_gerais.h"
#include "telas_relatorio.h"
#include "operacoes_cliente.h"
#include "operacoes_vestimenta.h"
#include "operacoes_locacao.h"

typedef struct cliente {
    char cpf[12];
    char nome[81];
    char nasc[9];
    char tel[14];
    char email[81];
    char status;
    Cliente *prox;
} Cliente;

typedef struct vestimenta {
    char id[14];
    char nome[81];
    int num_p;
    int num_m;
    int num_g;
    float preco;
    char status;
} Vestimenta; 

typedef struct locacao {
    long id_loc;
    char cpf[12];
    char id_vest[14];
    char tam_vest;
    char data_inicio[9];
    char data_fim[9];
    float valor;
    float multa;
    char status;
} Locacao;

char tela_relatorios(void) {
    system("clear||cls");
    char resposta;
    printf("###########################################################\n");
    printf("#                   R E L A T Ó R I O S                   #\n");
    printf("###########################################################\n");
    printf("#       1 - Relatório de clientes por ordem de cadastro   #\n");
    printf("#       2 - Relatório de clientes por ordem alfabética    #\n");
    printf("#       3 - Relatório de vestimentas                      #\n");
    printf("#       4 - Relatório de locações pendentes               #\n");
    printf("#       5 - Relatório de locações ativas                  #\n");
    printf("#       6 - Relatório de locações finalizadas             #\n");
    printf("#       0 - Retornar ao menu principal                    #\n");
    printf("###########################################################\n\n");
    printf("Escolha sua opção: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

void tela_relatorio_clientes(char ordem) {
    system("clear||cls");
    printf("###############################################\n");
    printf("#       L I S T A  D E  C L I E N T E S       #\n");
    printf("###############################################\n");
    if (ordem == 'c') {
        FILE* arq;
        Cliente *cl = (Cliente*) malloc(sizeof(Cliente));
        arq = fopen("clientes.dat", "rb");
        if (arq != NULL) {
            fread(cl, sizeof(Cliente), 1, arq);
            while (!feof(arq)) {
                if (cl->status != 'x') {
                    exibe_cliente(cl);
                    printf("###############################################\n");  
                }
                fread(cl, sizeof(Cliente), 1, arq);
            }
        }
        fclose(arq);
    }
    else if (ordem == 'a') {
        Cliente *cl = ordena_cliente();
        Cliente *temp = cl;
        while (cl != NULL) {
            exibe_cliente(cl);
            printf("###############################################\n");  
            cl = temp->prox;
            free(temp);
            temp = cl;
        }
    }
    printf("\nPressione ENTER para continuar ");
    getchar();
}

void tela_relatorio_vestimentas(void) {
    system("clear||cls");
    printf("###############################################\n");
    printf("#    L I S T A  D E  V E S T I M E N T A S    #\n");
    printf("###############################################\n");
    FILE* arq;
    Vestimenta *vest = (Vestimenta*) malloc(sizeof(Vestimenta));
    arq = fopen("vestimentas.dat", "rb");
    if (arq != NULL) {
        fread(vest, sizeof(Vestimenta), 1, arq);
        while (!feof(arq)) {
            if (vest->status != 'x') {
                exibe_vestimenta(vest);
                printf("###############################################\n");  
            }
            fread(vest, sizeof(Vestimenta), 1, arq);
        }
    }
    fclose(arq);
    printf("\nPressione ENTER para continuar ");
    getchar();
}

void tela_relatorio_locacoes(char status) {
    system("clear||cls");
    printf("###############################################\n");
    printf("#       L I S T A  D E  L O C A Ç Õ E S       #\n");
    printf("###############################################\n");
    FILE* arq;
    Locacao *loc = (Locacao*) malloc(sizeof(Locacao));
    arq = fopen("locacoes.dat", "rb");
    if (arq != NULL) {
        fread(loc, sizeof(Locacao), 1, arq);
        while (!feof(arq)) {
            if (loc->status == status) {
                Cliente *cl = busca_cliente(loc->cpf, 1);
                Vestimenta *vest = busca_vestimenta(loc->id_vest, 1);
                exibe_locacao(loc, cl, vest);
                printf("###############################################\n");  
                free(cl);
                free(vest);
            }
            fread(loc, sizeof(Locacao), 1, arq);
        }
    }
    fclose(arq);
    printf("\nPressione ENTER para continuar ");
    getchar();
}

void exibe_cliente(Cliente *cl) {
    printf("# CPF: %s\n", cl->cpf);
    printf("# Nome: %s\n", cl->nome);
    printf("# Data de nascimento: %s\n", cl->nasc);
    printf("# Telefone: %s\n", cl->tel);
    printf("# E-mail: %s\n", cl->email);
}

void exibe_vestimenta(Vestimenta *vest) {
    printf("# Código do produto: %s\n", vest->id);
    printf("# Nome da vestimenta: %s\n", vest->nome);
    printf("# Número de peças de tamanho P: %d\n", vest->num_p);
    printf("# Número de peças de tamanho M: %d\n", vest->num_m);
    printf("# Número de peças de tamanho G: %d\n", vest->num_g);
    printf("# Preço diário do aluguel: %.2f\n", vest->preco);
}

void exibe_locacao(Locacao *loc, Cliente *cl, Vestimenta *vest) {
    printf("# Código da locação: %ld\n", loc->id_loc);
    printf("# CPF do locatário: %s\n", loc->cpf);
    printf("# Nome do locatário: %s\n", cl->nome);
    printf("# Código da vestimenta alugada: %s\n", loc->id_vest);
    printf("# Nome da vestimenta alugada: %s\n", vest->nome);
    printf("# Tamanho da vestimenta alugada: %c\n", loc->tam_vest);
    printf("# Data de início da locação: %s\n", loc->data_inicio);
    printf("# Data de fim da locação: %s\n", loc->data_fim);
    printf("# Valor da locação (R$): %.2f\n", loc->valor);
    printf("# Valor da multa (R$): %.2f\n", loc->multa);
}

Cliente *ordena_cliente(void) {
    Cliente *lista = NULL;
    Cliente *novo_cl = (Cliente*) malloc(sizeof(Cliente));
    FILE* arq;
    arq = fopen("clientes.dat", "rb");
    if (arq != NULL) {     
        fread(novo_cl, sizeof(Cliente), 1, arq);
        while (!feof(arq)) {
            if (novo_cl->status != 'x') {
                if (lista == NULL) {
                    lista = novo_cl;
                    lista->prox = NULL;
                }
                else if (lista->prox == NULL) {
                    if (strcmp(lista->nome, novo_cl->nome) <= 0) {
                        lista->prox = novo_cl;
                    }
                    else {
                        novo_cl->prox = lista;
                        lista = novo_cl;
                    }
                }
                else {
                    lista = posiciona_cliente(lista, novo_cl);
                }
            }
            else {
                free(novo_cl);
            }
            novo_cl = (Cliente*) malloc(sizeof(Cliente));
            fread(novo_cl, sizeof(Cliente), 1, arq);
        }
        free(novo_cl);
        fclose(arq);
        return lista;
    }
    else {
        free(novo_cl);
        fclose(arq);
        return NULL;
    }
}

Cliente *posiciona_cliente(Cliente *lista, Cliente *novo_cl) {
    Cliente *anter = lista;
    Cliente *atual = lista->prox;
    int posicionou = 0;
    while (!posicionou) {
        if (strcmp(novo_cl->nome, lista->nome) <= 0) {
            novo_cl->prox = lista;
            lista = novo_cl;
            posicionou = 1;
        }
        else if (atual == NULL) {
            anter->prox = novo_cl;
            posicionou = 1;
        }
        else if ((strcmp(anter->nome, novo_cl->nome) <= 0) && (strcmp(novo_cl->nome, atual->nome) <= 0)) {
            anter->prox = novo_cl;
            novo_cl->prox = atual;
            posicionou = 1;
        }
        else {
            anter = atual;
            atual = anter->prox;
        }
    }
    return lista;
}