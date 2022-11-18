#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telas_vestimenta.h"
#include "operacoes_vestimenta.h"
#include "operacoes_gerais.h"
#include "validacoes.h"

typedef struct vestimenta {
    char id[14];
    char nome[81];
    int num_p;
    int num_m;
    int num_g;
    float preco;
    char status;
} Vestimenta; 

void cadastrar_vestimenta(void) {
    Vestimenta *vest = (Vestimenta*) malloc(sizeof(Vestimenta));
    tela_cadastro_vestimenta(vest);
    int id_ja_existe = 1;
    do {
        gera_codigo_barras(vest->id);
        id_ja_existe = verifica_exist_vest(vest->id);
    } while (id_ja_existe == 1);
    vest->status = 'c';
    grava_vestimenta(vest);
    printf("\nCadastro realizado com sucesso!\n\n");
    printf("Número de identificação: %s\n", vest->id);
    printf("Nome da vestimenta: %s\n", vest->nome);
    printf("Número de unidades de tamanho P: %d\n", vest->num_p);
    printf("Número de unidades de tamanho M: %d\n", vest->num_m);
    printf("Número de unidades de tamanho G: %d\n", vest->num_g);
    printf("Preço da locação diária (R$): %.2f\n\n", vest->preco);
    printf("Pressione ENTER para continuar ");
    getchar();
    free(vest);
}

void info_vestimenta(void) {
    char *num_id = (char*) malloc(14*sizeof(char));
    printf("\nInforme o código de barras da vestimenta: ");
    scanf("%s", num_id);
    getchar();
    Vestimenta *vest = busca_vestimenta(num_id, 0);
    if (vest != NULL) {
        tela_info_vestimenta(vest);
    }
    else {
        printf("\nNão foi encontrada nenhuma vestimenta com este código.\n\n");
        printf("Pressione ENTER para continuar ");
        getchar();
    }
    free(vest);
    free(num_id);
}

void alterar_vestimenta(void) {
    char resp = '1';
    char *id = (char*) malloc(14*sizeof(char));
    printf("\nInforme o código da vestimenta: ");
    scanf("%s", id);
    getchar();
    Vestimenta *vest = busca_vestimenta(id, 0);
    if (vest != NULL) {
        while (resp != '0') {
            resp = tela_alterar_vestimenta(vest);
            if (resp == '1') {
                cad_nome_vest(vest->nome);
                edita_vestimenta(vest);
                printf("\nAlteração realizada com sucesso!\n\n");
                printf("Pressione ENTER para continuar ");
                getchar();
            }
            else if (resp == '2') {
                cad_num_vest(&vest->num_p, 'P');
                edita_vestimenta(vest);
                printf("\nAlteração realizada com sucesso!\n\n");
                printf("Pressione ENTER para continuar ");
                getchar();
            }
            else if (resp == '3') {
                cad_num_vest(&vest->num_m, 'M');
                edita_vestimenta(vest);
                printf("\nAlteração realizada com sucesso!\n\n");
                printf("Pressione ENTER para continuar ");
                getchar();
            }
            else if (resp == '4') {
                cad_num_vest(&vest->num_g, 'G');
                edita_vestimenta(vest);
                printf("\nAlteração realizada com sucesso!\n\n");
                printf("Pressione ENTER para continuar ");
                getchar();
            }
            else if (resp == '5') {
                cad_preco_vest(&vest->preco);
                edita_vestimenta(vest);
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
        printf("\nNão foi encontrada nenhuma vestimenta com este código.\n\n");
        printf("Pressione ENTER para continuar ");
        getchar();
    }
    free(vest);
}

void remover_vestimenta(void) {
    char resp = '2';
    char *id = (char*) malloc(14*sizeof(char));
    printf("\nInforme o código da vestimenta: ");
    scanf("%s", id);
    getchar();
    Vestimenta *vest = busca_vestimenta(id, 0);
    if (vest != NULL) {
        resp = tela_remover_vestimenta(vest);
        if (resp == '1') {
            printf("\nVestimenta removida.\n\n");
            exclui_vestimenta(id);
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
        printf("\nNão foi encontrada nenhuma vestimenta com este código.\n\n");
        printf("Pressione ENTER para continuar ");
        getchar();
    }
    free(vest);
}

void grava_vestimenta(Vestimenta *vest) {
    FILE* arq;
    arq = fopen("vestimentas.dat", "ab");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo!\n\n");
        printf("Pressione ENTER para continuar ");
        getchar();
    }
    else {
        fwrite(vest, sizeof(Vestimenta), 1, arq);
    }
    fclose(arq);
}

Vestimenta *busca_vestimenta(char *id, int incluir_excluido) {
    FILE* arq;
    Vestimenta *vest = (Vestimenta*) malloc(sizeof(Vestimenta));
    arq = fopen("vestimentas.dat", "rb");
    if (arq == NULL) {
        fclose(arq);
        return NULL;
    }
    else {
        while (!feof(arq)) {
            fread(vest, sizeof(Vestimenta), 1, arq);
            if (!strcmp(vest->id, id) && (vest->status != 'x' || incluir_excluido)) {
                fclose(arq);
                return vest;
            }
        }
    }
    fclose(arq);
    return NULL;
}

void edita_vestimenta(Vestimenta *vest_lida) {
    FILE* arq;
    Vestimenta *vest_arq = (Vestimenta*) malloc(sizeof(Vestimenta));
    arq = fopen("vestimentas.dat", "r+b");
    int encontrado = 0;
    if (arq == NULL) {
        printf("Erro ao abrir arquivo!\n\n");
        printf("Pressione ENTER para continuar ");
        getchar();
    }
    while (!feof(arq)) {
        fread(vest_arq, sizeof(Vestimenta), 1, arq);
        if (!strcmp(vest_lida->id, vest_arq->id) && vest_arq->status != 'x') {
            encontrado = 1;
            fseek(arq, -1*sizeof(Vestimenta), SEEK_CUR);
            fwrite(vest_lida, sizeof(Vestimenta), 1, arq);
            fclose(arq);
            free(vest_arq);
            break;
        }
    }
    fclose(arq);
    free(vest_arq);
    if (!encontrado) {
        printf("Vestimenta não encontrada!\n\n");
        printf("Pressione ENTER para continuar ");
        getchar();
    }
}

void exclui_vestimenta(char *id) {
    FILE* arq;
    Vestimenta *vest = (Vestimenta*) malloc(sizeof(Vestimenta));
    arq = fopen("vestimentas.dat", "r+b");
    int encontrado = 0;
    if (arq == NULL) {
        printf("Erro ao abrir arquivo!\n\n");
        printf("Pressione ENTER para continuar ");
        getchar();
    }
    while (!feof(arq)) {
        fread(vest, sizeof(Vestimenta), 1, arq);
        if (!strcmp(id, vest->id) && vest->status != 'x') {
            encontrado = 1;
            vest->status = 'x';
            fseek(arq, -1*sizeof(Vestimenta), SEEK_CUR);
            fwrite(vest, sizeof(Vestimenta), 1, arq);
            fclose(arq);
            free(vest);
            break;
        }
    }
    fclose(arq);
    free(vest);
    if (!encontrado) {
        printf("Vestimenta não encontrada!\n\n");
        printf("Pressione ENTER para continuar ");
        getchar();
    }
}

int disponibilidade_vest(char *id_vest, char tam_vest) {
    Vestimenta *vest = busca_vestimenta(id_vest, 0);
    if ((tam_vest == 'P' || tam_vest == 'p') && vest->num_p > 0) {
        free(vest);
        return 1;
    }
    else if ((tam_vest == 'M' || tam_vest == 'm') && vest->num_m > 0) {
        free(vest);
        return 1;
    }
    else if ((tam_vest == 'G' || tam_vest == 'g') && vest->num_g > 0) {
        free(vest);
        return 1;
    }
    free(vest);
    return 0;
}