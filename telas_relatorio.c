#include <stdio.h>
#include <stdlib.h>
#include "telas_gerais.h"
#include "operacoes_cliente.h"
#include "operacoes_vestimenta.h"
#include "operacoes_locacao.h"

char tela_relatorios(void) {
    system("clear||cls");
    char resposta;
    printf("###############################################\n");
    printf("#             R E L A T O R I O S             #\n");
    printf("###############################################\n");
    printf("#       1 - Relatorio de clientes             #\n");
    printf("#       2 - Relatorio de vestimentas          #\n");
    printf("#       3 - Relatorio de locacoes             #\n");
    printf("#       0 - Retornar ao menu principal        #\n");
    printf("###############################################\n\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

void tela_relatorio_clientes(void) {
    system("clear||cls");
    printf("Lista de clientes:\n\n");
    //Exibe lista de clientes
    printf("Pressione ENTER para continuar ");
    getchar();
}

void tela_relatorio_vestimentas(void) {
    system("clear||cls");
    printf("Lista de vestimentas:\n\n");
    //Exibe lista de vestimentas
    printf("Pressione ENTER para continuar ");
    getchar();
}

void tela_relatorio_locacoes(void) {
    system("clear||cls");
    printf("Lista de locacoes:\n\n");
    //Exibe lista de locações
    printf("Pressione ENTER para continuar ");
    getchar();
}