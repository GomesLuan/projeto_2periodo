#include <stdio.h>
#include <stdlib.h>
#include "telas_locacoes.h"

//Variável provisória
char locacao[6][50] = {"123456", "12345678909", "Fantasia do Batman", "M", "01/01/2023", "03/01/2023"};

void cadastrar_locacao(void) {
    char *tam_vest = (char*) malloc(2*sizeof(char));
    char *cpf = (char*) malloc(12*sizeof(char));
    char *id_vest = (char*) malloc(7*sizeof(char));
    char *data_inicio = (char*) malloc(11*sizeof(char));
    char *data_fim = (char*) malloc(11*sizeof(char));
    tela_cadastro_locacao(cpf, id_vest, tam_vest, data_inicio, data_fim); 
    //Adição dos dados à lista
    printf("\nAgendamento realizado com sucesso!\n\n");
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
    char resp = '1';
    //Input com o numero de identificação do aluguel
    //Busca das informações do aluguel solicitada
    while (resp != '0') {
        resp = tela_alterar_locacao(locacao[1], locacao[2], locacao[3], locacao[4], locacao[5]);
        if (resp == '1') {
            char *novo_cpf = malloc(12* sizeof(char));
            printf("\nPor favor informe o novo CPF do cliente responsável (apenas números): ");
            scanf("%s", novo_cpf);
            getchar();
            //mudar cpf
            //desalocar memoria
            printf("\nAlteração realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp == '2') {
            char *novo_nome = malloc(51* sizeof(char));
            printf("\nPor favor informe o novo nome da vestimenta que deseja alugar: ");
            scanf("%s", novo_nome);
            getchar();
            //mudar nome de vestimenta
            //desalocar memoria
            printf("\nAlteração realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp == '3') {
            char *novo_tam = malloc(2* sizeof(char));
            printf("\nPor favor informe o novo tamanho da vestimenta que deseja alugar: ");
            scanf("%s", novo_tam);
            getchar();
            //Alteração do tamanho da vestimenta
            //desalocar memoria
            printf("\nAlteração realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp == '4') {
            char *novo_inicio = malloc(11* sizeof(char));
            printf("\nPor favor informe a nova data de início da locação (ddmmaaaa): ");
            scanf("%s", novo_inicio);
            getchar();
            //Alteração da data de inicio da locacao
            //desalocar memoria
            printf("\nAlteração realizada com sucesso!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
        else if (resp == '5') {
            char *novo_fim = malloc(11* sizeof(char));
            printf("\nPor favor informe a nova data de fim da locação (ddmmaaaa): ");
            scanf("%s", novo_fim);
            getchar();
            //Alteração da data de fim da locacao
            //desalocar memoria
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

void remover_locacao(void) {
    //char *num;
    char resp = '2';
    //Input com o numero de identificação do contrato
    //Busca das informações do contrato solicitado
    resp = tela_remover_locacao(locacao[0], locacao[1], locacao[2], locacao[3], locacao[4], locacao[5]);
    if (resp == '1') {
        printf("\nAgendamento cancelado.\n\n");
        //remove contrato da lista
        //desalocar memoria
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

void receber_produto_alugado(void) {
    //char *num;
    char resp = '2';
    //Input com o numero de identificação do contrato
    //Busca das informações do contrato solicitado
    //Teste se o contrato está pendente
    resp = tela_receber_produto(locacao[0], locacao[1], locacao[2], locacao[3], locacao[4], locacao[5]);
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
}

void devolver_produto_alugado(void) {
    //char *num;
    char resp = '2';
    //Input com o numero de identificação do contrato
    //Busca das informações do contrato solicitado
    //Teste se o contrato está ativo
    resp = tela_devolver_produto(locacao[0], locacao[1], locacao[2], locacao[3], locacao[4], locacao[5]);
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
}