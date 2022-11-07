#include <stdio.h>
#include <stdlib.h>
#include "telas_gerais.h"
#include "operacoes_cliente.h"
#include "operacoes_vestimenta.h"
#include "operacoes_locacao.h"

typedef struct cliente {
    char cpf[12];
    char nome[81];
    char nasc[9];
    char tel[14];
    char email[81];
} Cliente;

typedef struct vestimenta {
    char id[14];
    char nome[81];
    int num_p;
    int num_m;
    int num_g;
    float preco;
} Vestimenta; 

typedef struct locacao {
    long id_loc;
    char cpf[12];
    char id_vest[14];
    char tam_vest;
    char data_inicio[9];
    char data_fim[9];
} Locacao;

char tela_relatorios(void) {
    system("clear||cls");
    char resposta;
    printf("###############################################\n");
    printf("#             R E L A T Ó R I O S             #\n");
    printf("###############################################\n");
    printf("#       1 - Relatório de clientes             #\n");
    printf("#       2 - Relatório de vestimentas          #\n");
    printf("#       3 - Relatório de locações             #\n");
    printf("#       0 - Retornar ao menu principal        #\n");
    printf("###############################################\n\n");
    printf("Escolha sua opção: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

void tela_relatorio_clientes(void) {
    system("clear||cls");
    printf("###############################################\n");
    printf("#       L I S T A  D E  C L I E N T E S       #\n");
    printf("###############################################\n");
    FILE* arq;
    Cliente *cl = (Cliente*) malloc(sizeof(Cliente));
    arq = fopen("clientes.dat", "rb");
    if (arq != NULL) {
        fread(cl, sizeof(Cliente), 1, arq);
        while (!feof(arq)) {
            printf("# CPF: %s\n", cl->cpf);
            printf("# Nome: %s\n", cl->nome);
            printf("# Data de nascimento: %s\n", cl->nasc);
            printf("# Telefone: %s\n", cl->tel);
            printf("# E-mail: %s\n", cl->email);
            printf("###############################################\n");  
            fread(cl, sizeof(Cliente), 1, arq);
        }
    }
    fclose(arq);
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
            printf("# Código do produto: %s\n", vest->id);
            printf("# Nome da vestimenta: %s\n", vest->nome);
            printf("# Número de peças de tamanho P: %d\n", vest->num_p);
            printf("# Número de peças de tamanho M: %d\n", vest->num_m);
            printf("# Número de peças de tamanho G: %d\n", vest->num_g);
            printf("# Preço diário do aluguel: %.2f\n", vest->preco);
            printf("###############################################\n");  
            fread(vest, sizeof(Vestimenta), 1, arq);
        }
    }
    fclose(arq);
    printf("\nPressione ENTER para continuar ");
    getchar();
}

void tela_relatorio_locacoes(void) {
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
            printf("# Código da locação: %ld\n", loc->id_loc);
            printf("# CPF do locatário: %s\n", loc->cpf);
            printf("# Código da vestimenta alugada: %s\n", loc->id_vest);
            printf("# Tamanho da vestimenta alugada: %c\n", loc->tam_vest);
            printf("# Data de início da locação: %s\n", loc->data_inicio);
            printf("# Data de fim da locação: %s\n", loc->data_fim);
            printf("###############################################\n");  
            fread(loc, sizeof(Locacao), 1, arq);
        }
    }
    fclose(arq);
    printf("\nPressione ENTER para continuar ");
    getchar();
}
