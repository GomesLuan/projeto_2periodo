#include <stdio.h>
#include <stdlib.h>
#include "telas_vestimenta.h"

//Variável provisória
char vestimenta[5][50] = {"Fantasia do Batman", "3", "2", "5", "90.00"};

void cadastrar_vestimenta(void) {
    char *nome = malloc(50* sizeof(char));
    int num_p, num_m, num_g;
    float preco;
    tela_cadastro_vestimenta(&nome, &num_p, &num_m, &num_g, &preco);
    //Adição dos dados à lista
    printf("\nCadastro realizado com sucesso!\n\n");
    printf("Pressione ENTER para continuar ");
    getchar();
}

void info_vestimenta(void) {
    //char *nome;
    //Input com o nome de identificação da vestimenta
    //Busca das informações da vestimenta solicitada
    tela_info_vestimenta(vestimenta[0], vestimenta[1], vestimenta[2], vestimenta[3], vestimenta[4]);
}

void alterar_vestimenta(void) {
    //char *nome;
    char *novo_valor = malloc(50* sizeof(char));
    char resp = '1';
    //Input com o nome de identificação da vestimenta
    //Busca das informações da vestimenta solicitada
    while (resp != '0') {
        resp = tela_alterar_vestimenta(vestimenta[1], vestimenta[2], vestimenta[3], vestimenta[4]);
        if (resp == '1') {
            printf("\nPor favor informe o novo numero de unidades de tamanho P: ");
            scanf("%s", novo_valor);
            getchar();
            //Alteração do número de unidades de tamanho P na lista
            printf("\nAlteracao realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp == '2') {
            printf("\nPor favor informe o novo numero de unidades de tamanho M: ");
            scanf("%s", novo_valor);
            getchar();
            //Alteração do número de unidades de tamanho M na lista
            printf("\nAlteracao realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp == '3') {
            printf("\nPor favor informe o novo numero de unidades de tamanho G: ");
            scanf("%s", novo_valor);
            getchar();
            //Alteração do número de unidades de tamanho G na lista
            printf("\nAlteracao realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp == '4') {
            printf("\nPor favor informe o novo preco da locacao diaria: ");
            scanf("%s", novo_valor);
            getchar();
            //Alteração do preco da locacao diaria na lista
            printf("\nAlteracao realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp != '0') {
            printf("\nValor invalido!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
    }
}

void remover_vestimenta(void) {
    //char *nome;
    char resp = '2';
    //Input com o nome de identificação da vestimenta
    //Busca das informações da vestimenta solicitada
    resp = tela_remover_vestimenta(vestimenta[0], vestimenta[1], vestimenta[2], vestimenta[3], vestimenta[4]);
    if (resp == '1') {
        printf("\nVestimenta removida.\n\n");
        //remove vestimenta da lista
    }
    else if (resp == '2') {
        printf("\nRetornando...\n\n");
    }
    else {
        printf("\nValor invalido!\n\n");
    }
    printf("Pressione ENTER para continuar ");
    getchar();
}