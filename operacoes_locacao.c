#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "validacoes.h"
#include "telas_locacoes.h"
#include "operacoes_locacao.h"
#include "operacoes_gerais.h"

typedef struct locacao {
    long id_loc;
    char cpf[12];
    char id_vest[14];
    char tam_vest;
    char data_inicio[9];
    char data_fim[9];
    char status;
} Locacao;

void cadastrar_locacao(void) {
    Locacao *loc = (Locacao*) malloc(sizeof(Locacao));
    tela_cadastro_locacao(loc); 
    int id_ja_existe = 1;
    do {
        loc->id_loc = time(0);
        id_ja_existe = verifica_exist_loc(loc->id_loc);
    } while (id_ja_existe == 1);
    loc->status = 'p'; //pendente
    grava_locacao(loc);
    printf("\nAgendamento realizado com sucesso!\n\n");
    printf("Código da locação: %ld\n", loc->id_loc);
    printf("CPF do cliente locatário: %s\n", loc->cpf);
    printf("Código da vestimenta alugada: %s\n", loc->id_vest);
    printf("Tamanho da vestimenta alugada: %c\n", loc->tam_vest);
    printf("Data de início da locação: %s\n", loc->data_inicio);
    printf("Data de fim da locação: %s\n\n", loc->data_fim);
    printf("Pressione ENTER para continuar ");
    getchar();
    free(loc);
}

void info_locacao(void) {
    char *id_str = (char*) malloc(11*sizeof(char));
    printf("\nInforme o código da locação: ");
    scanf("%s", id_str);
    getchar();
    long id = converte_str_para_int(id_str);
    Locacao *loc = busca_locacao(id, 0);
    if (loc != NULL) {
        tela_info_locacao(loc);
    }
    else {
        printf("\nNão foi encontrada nenhuma locação com este código.\n\n");
        printf("Pressione ENTER para continuar ");
        getchar();
    }
    free(loc);
    free(id_str);
}

void alterar_locacao(void) {
    char resp = '1';
    char *id_str = (char*) malloc(14*sizeof(char));
    printf("\nInforme o código da locação: ");
    scanf("%s", id_str);
    getchar();
    long id = converte_str_para_int(id_str);
    Locacao *loc = busca_locacao(id, 0);
    if (loc != NULL && loc->status == 'p') {
        while (resp != '0') {
            resp = tela_alterar_locacao(loc);
            if (resp == '1') {
                cad_cpf_locatario(loc->cpf);
                edita_locacao(loc);
                printf("\nAlteração realizada com sucesso!\n\n");
                printf("Pressione ENTER para continuar ");
                getchar();
            }
            else if (resp == '2') {
                cad_id_vest(loc->id_vest);
                edita_locacao(loc);
                printf("\nAlteração realizada com sucesso!\n\n");
                printf("Pressione ENTER para continuar ");
                getchar();
            }
            else if (resp == '3') {
                cad_tam_vest(&loc->tam_vest, loc->id_vest);
                edita_locacao(loc);
                printf("\nAlteração realizada com sucesso!\n\n");
                printf("Pressione ENTER para continuar ");
                getchar();
            }
            else if (resp == '4') {
                cad_data_inicio(loc->data_inicio);
                edita_locacao(loc);
                printf("\nAlteração realizada com sucesso!\n\n");
                printf("Pressione ENTER para continuar ");
                getchar();
            }
            else if (resp == '5') {
                cad_data_fim(loc->data_fim, loc->data_inicio);
                edita_locacao(loc);
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
        printf("\nA locação não existe ou já passou do período de alteração.\n\n");
        printf("Pressione ENTER para continuar ");
        getchar();
    }
    free(loc);
}

void remover_locacao(void) {
    char resp = '1';
    char *id_str = (char*) malloc(14*sizeof(char));
    printf("\nInforme o código da locação: ");
    scanf("%s", id_str);
    getchar();
    long id = converte_str_para_int(id_str);
    Locacao *loc = busca_locacao(id, 0);
    if (loc != NULL && loc->status == 'p') {
        resp = tela_remover_locacao(loc);
        if (resp == '1') {
            printf("\nAgendamento cancelado.\n\n");
            exclui_locacao(id);
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
        printf("\nA locação não existe ou já passou do período de cancelamento.\n\n");
        printf("Pressione ENTER para continuar ");
        getchar();
    }
    free(loc);
}

void receber_produto_alugado(void) {
    //char *num;
    char resp = '2';
    //Input com o numero de identificação do contrato
    //Busca das informações do contrato solicitado
    //Teste se o contrato está pendente
    Locacao *loc = (Locacao*) malloc(sizeof(Locacao));
    loc->id_loc = 1667231055;
    strcpy(loc->cpf, "12345678909");
    strcpy(loc->id_vest, "1564798136123");
    loc->tam_vest = 'M';
    strcpy(loc->data_inicio, "01012022");
    strcpy(loc->data_fim, "03012002");
    resp = tela_receber_produto(loc);
    if (resp == '1') {
        printf("\nProduto recebido!\n\n");
        //muda o status da locação de pendente para ativa
        //remove uma unidade da vestimenta
    }
    else if (resp == '2') {
        printf("\nRetornando...\n\n");
    }
    else {
        printf("\nValor inválido!\n\n");
    }
    printf("Pressione ENTER para continuar ");
    getchar();
    free(loc);
}

void devolver_produto_alugado(void) {
    //char *num;
    char resp = '2';
    //Input com o numero de identificação do contrato
    //Busca das informações do contrato solicitado
    //Teste se o contrato está ativo
    Locacao *loc = (Locacao*) malloc(sizeof(Locacao));
    loc->id_loc = 1667231055;
    strcpy(loc->cpf, "12345678909");
    strcpy(loc->id_vest, "1564798136123");
    loc->tam_vest = 'M';
    strcpy(loc->data_inicio, "01012022");
    strcpy(loc->data_fim, "03012002");
    resp = tela_devolver_produto(loc);
    if (resp == '1') {
        printf("\nProduto devolvido!\n\n");
        //adiciona uma unidade da vestimenta
        //muda o status da locação de ativa para finalizada
    }
    else if (resp == '2') {
        printf("\nRetornando...\n\n");
    }
    else {
        printf("\nValor inválido!\n\n");
    }
    printf("Pressione ENTER para continuar ");
    getchar();
    free(loc);
}

void grava_locacao(Locacao *loc) {
    FILE* arq;
    arq = fopen("locacoes.dat", "ab");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo!\n\n");
        printf("Pressione ENTER para continuar ");
        getchar();
    }
    else {
        fwrite(loc, sizeof(Locacao), 1, arq);
    }
    fclose(arq);
}

Locacao *busca_locacao(long id, int incluir_excluido) {
    FILE* arq;
    Locacao *loc = (Locacao*) malloc(sizeof(Locacao));
    arq = fopen("locacoes.dat", "rb");
    if (arq == NULL) {
        fclose(arq);
        return NULL;
    }
    else {
        while (!feof(arq)) {
            fread(loc, sizeof(Locacao), 1, arq);
            if (loc->id_loc == id && (loc->status != 'x' || incluir_excluido)) {
                fclose(arq);
                return loc;
            }
        }
    }
    fclose(arq);
    return NULL;
}

void edita_locacao(Locacao *loc_lida) {
    FILE* arq;
    Locacao *loc_arq = (Locacao*) malloc(sizeof(Locacao));
    arq = fopen("locacoes.dat", "r+b");
    int encontrado = 0;
    if (arq == NULL) {
        printf("Erro ao abrir arquivo!\n\n");
        printf("Pressione ENTER para continuar ");
        getchar();
    }
    while (!feof(arq)) {
        fread(loc_arq, sizeof(Locacao), 1, arq);
        if (loc_lida->id_loc == loc_arq->id_loc && loc_arq->status != 'x') {
            encontrado = 1;
            fseek(arq, -1*sizeof(Locacao), SEEK_CUR);
            fwrite(loc_lida, sizeof(Locacao), 1, arq);
            fclose(arq);
            free(loc_arq);
            break;
        }
    }
    fclose(arq);
    free(loc_arq);
    if (!encontrado) {
        printf("Locação não encontrada!\n\n");
        printf("Pressione ENTER para continuar ");
        getchar();
    }
}

void exclui_locacao(long id) {
    FILE* arq;
    Locacao *loc = (Locacao*) malloc(sizeof(Locacao));
    arq = fopen("locacoes.dat", "r+b");
    int encontrado = 0;
    if (arq == NULL) {
        printf("Erro ao abrir arquivo!\n\n");
        printf("Pressione ENTER para continuar ");
        getchar();
    }
    while (!feof(arq)) {
        fread(loc, sizeof(Locacao), 1, arq);
        if (loc->id_loc == id && loc->status != 'x') {
            encontrado = 1;
            loc->status = 'x';
            fseek(arq, -1*sizeof(Locacao), SEEK_CUR);
            fwrite(loc, sizeof(Locacao), 1, arq);
            fclose(arq);
            free(loc);
            break;
        }
    }
    fclose(arq);
    free(loc);
    if (!encontrado) {
        printf("Locação não encontrada!\n\n");
        printf("Pressione ENTER para continuar ");
        getchar();
    }
}