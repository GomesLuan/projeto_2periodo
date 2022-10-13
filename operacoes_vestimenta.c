#include <stdio.h>
#include <stdlib.h>
#include "telas_vestimenta.h"

//Variável provisória
char vestimenta[6][50] = {"123456", "Fantasia do Batman", "3", "2", "5", "90.00"};

void cadastrar_vestimenta(void) {
    char *num_id = (char*) malloc(7*sizeof(char));
    char *nome = (char*) malloc(50*sizeof(char));
    char *num_p = (char*) malloc(3*sizeof(char));
    char *num_m = (char*) malloc(3*sizeof(char));
    char *num_g = (char*) malloc(3*sizeof(char));
    char *preco = (char*) malloc(10*sizeof(char));
    tela_cadastro_vestimenta(num_id, nome, num_p, num_m, num_g, preco);
    //Adição dos dados à lista
    printf("\nCadastro realizado com sucesso!\n\n");
    printf("Pressione ENTER para continuar ");
    getchar();
}

void info_vestimenta(void) {
    //char *num_id;
    //Input com o número de identificação da vestimenta
    //Busca das informações da vestimenta solicitada
    tela_info_vestimenta(vestimenta[0], vestimenta[1], vestimenta[2], vestimenta[3], vestimenta[4], vestimenta[5]);
}

void alterar_vestimenta(void) {
    //char *num_id;
    char resp = '1';
    //Input com o número de identificação da vestimenta
    //Busca das informações da vestimenta solicitada
    while (resp != '0') {
        resp = tela_alterar_vestimenta(vestimenta[1], vestimenta[2], vestimenta[3], vestimenta[4], vestimenta[5]);
        if (resp == '1') {
            char *novo_nome = malloc(50* sizeof(char));
            printf("\nPor favor informe o novo nome da vestimenta: ");
            scanf("%s", novo_nome);
            getchar();
            //Alteração do nome da vestimenta na lista
            //desalocar memória
            printf("\nAlteração realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp == '2') {
            char *novo_num_p = malloc(3* sizeof(char));
            printf("\nPor favor informe o novo número de unidades de tamanho P: ");
            scanf("%s", novo_num_p);
            getchar();
            //Alteração do número de unidades de tamanho P na lista
            //desalocar memória
            printf("\nAlteração realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp == '3') {
            char *novo_num_m = malloc(3* sizeof(char));
            printf("\nPor favor informe o novo número de unidades de tamanho M: ");
            scanf("%s", novo_num_m);
            getchar();
            //Alteração do número de unidades de tamanho M na lista
            //desalocar memória
            printf("\nAlteração realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp == '4') {
            char *novo_num_g = malloc(3* sizeof(char));
            printf("\nPor favor informe o novo número de unidades de tamanho G: ");
            scanf("%s", novo_num_g);
            getchar();
            //Alteração do número de unidades de tamanho G na lista
            //desalocar memória
            printf("\nAlteração realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp == '5') {
            char *novo_preco = malloc(10* sizeof(char));
            printf("\nPor favor informe o novo preço da locacao diária: ");
            scanf("%s", novo_preco);
            getchar();
            //Alteração do preco da locação diária na lista
            //desalocar memória
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

void remover_vestimenta(void) {
    //char *num_id;
    char resp = '2';
    //Input com o nome de identificação da vestimenta
    //Busca das informações da vestimenta solicitada
    resp = tela_remover_vestimenta(vestimenta[0], vestimenta[1], vestimenta[2], vestimenta[3], vestimenta[4], vestimenta[5]);
    if (resp == '1') {
        printf("\nVestimenta removida.\n\n");
        //remove vestimenta da lista
        //desalocar memória
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