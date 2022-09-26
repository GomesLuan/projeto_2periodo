#include <stdio.h>
#include <stdlib.h>
#include "telas_locacoes.h"

//Variável provisória
char locacao[6][50] = {"123456", "12345678909", "Fantasia do Batman", "M", "01/01/2023", "03/01/2023"};

void cadastrar_locacao(void) {
    char tam_vest;
    char *num_id = malloc(50* sizeof(char));
    char *cpf = malloc(50* sizeof(char));
    char *nome_vest = malloc(50* sizeof(char));
    char *data_inicio = malloc(50* sizeof(char));
    char *data_fim = malloc(50* sizeof(char));
    tela_cadastro_locacao(&num_id, &cpf, &nome_vest, &tam_vest, &data_inicio, &data_fim); 
    //Adição dos dados à lista
    printf("\nContrato realizado com sucesso!\n\n");
    printf("Pressione ENTER para continuar ");
    getchar();
}

void info_locacao(void) {
    //char *num;
    //Input com o numero de identificação do aluguel
    //Busca das informações do aluguel solicitada
    tela_info_locacao(locacao[0], locacao[1], locacao[2], locacao[3], locacao[4], locacao[5]);
}

void alterar_locacao(void) {
    //char *num;
    char *novo_valor = malloc(50* sizeof(char));
    char resp = '1';
    //Input com o numero de identificação do aluguel
    //Busca das informações do aluguel solicitada
    while (resp != '0') {
        resp = tela_alterar_locacao(locacao[1], locacao[2], locacao[3], locacao[4], locacao[5]);
        if (resp == '1') {
            printf("\nPor favor informe o novo CPF do cliente responsavel: ");
            scanf("%s", novo_valor);
            getchar();
            //mudar cpf
            printf("\nAlteracao realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp == '2') {
            printf("\nPor favor informe o novo nome da vestimenta que deseja alugar: ");
            scanf("%s", novo_valor);
            getchar();
            //mudar nome de vestimenta
            printf("\nAlteracao realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp == '3') {
            printf("\nPor favor informe o novo tamanho da vestimenta que deseja alugar: ");
            scanf("%s", novo_valor);
            getchar();
            //Alteração da data de inicio da locacao
            printf("\nAlteracao realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp == '4') {
            printf("\nPor favor informe a nova data de inicio da locacao: ");
            scanf("%s", novo_valor);
            getchar();
            //Alteração da data de inicio da locacao
            printf("\nAlteracao realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp == '5') {
            printf("\nPor favor informe a nova data de fim da locacao: ");
            scanf("%s", novo_valor);
            getchar();
            //Alteração da data de fim da locacao
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

void remover_locacao(void) {
    //char *num;
    char resp = '2';
    //Input com o numero de identificação do contrato
    //Busca das informações do contrato solicitado
    resp = tela_remover_locacao(locacao[0], locacao[1], locacao[2], locacao[3], locacao[4], locacao[5]);
    if (resp == '1') {
        printf("\nContrato cancelado.\n\n");
        //remove contrato da lista
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