#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telas_vestimenta.h"
#include "operacoes_gerais.h"

void cadastrar_vestimenta(void) {
    Vestimenta *vest = (Vestimenta*) malloc(sizeof(Vestimenta));
    //existe_id = 0
    tela_cadastro_vestimenta(vest);
    gera_codigo_barras(vest->id);
    //verifica se o id gerado já está cadastrado
    //Adição dos dados ao arquivo
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
    //char *num_id;
    //Input com o número de identificação da vestimenta
    //Busca das informações da vestimenta solicitada
    Vestimenta *vest = (Vestimenta*) malloc(sizeof(Vestimenta));
    strcpy(vest->id, "1564798136123");
    strcpy(vest->nome, "Camiseta verde");
    vest->num_p = 4;
    vest->num_m = 2;
    vest->num_g = 3;
    vest->preco = 50.00;
    tela_info_vestimenta(vest);
    free(vest);
}

void alterar_vestimenta(void) {
    //char *num_id;
    char resp = '1';
    //Input com o número de identificação da vestimenta
    //Busca das informações da vestimenta solicitada
    Vestimenta *vest = (Vestimenta*) malloc(sizeof(Vestimenta));
    strcpy(vest->id, "1564798136123");
    strcpy(vest->nome, "Camiseta verde");
    vest->num_p = 4;
    vest->num_m = 2;
    vest->num_g = 3;
    vest->preco = 50.00;
    while (resp != '0') {
        resp = tela_alterar_vestimenta(vest);
        if (resp == '1') {
            cad_nome_vest(vest->nome);
            //Alteração do nome da vestimenta no arquivo
            printf("\nAlteração realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp == '2') {
            cad_num_vest(&vest->num_p, 'P');
            //Alteração do número de unidades de tamanho P no arquivo
            printf("\nAlteração realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp == '3') {
            cad_num_vest(&vest->num_m, 'M');
            //Alteração do número de unidades de tamanho M no arquivo
            printf("\nAlteração realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp == '4') {
            cad_num_vest(&vest->num_g, 'G');
            //Alteração do número de unidades de tamanho G no arquivo
            printf("\nAlteração realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp == '5') {
            cad_preco_vest(&vest->preco);
            //Alteração do preco da locação diária no arquivo
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
    free(vest);
}

void remover_vestimenta(void) {
    //char *num_id;
    char resp = '2';
    //Input com o nome de identificação da vestimenta
    //Busca das informações da vestimenta solicitada
    Vestimenta *vest = (Vestimenta*) malloc(sizeof(Vestimenta));
    strcpy(vest->id, "1564798136123");
    strcpy(vest->nome, "Camiseta verde");
    vest->num_p = 4;
    vest->num_m = 2;
    vest->num_g = 3;
    vest->preco = 50.00;
    resp = tela_remover_vestimenta(vest);
    if (resp == '1') {
        printf("\nVestimenta removida.\n\n");
        //remove vestimenta do arquivo
    }
    else if (resp == '2') {
        printf("\nRetornando...\n\n");
    }
    else {
        printf("\nValor inválido!\n\n");
    }
    printf("Pressione ENTER para continuar ");
    getchar();
    free(vest);
}