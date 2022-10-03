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
    printf("#                                             #\n");
    //Exibe lista de clientes
    printf("###############################################\n\n");
    printf("Pressione ENTER para continuar ");
    getchar();
}
void tela_relatorio_vestimentas(void) {
    system("clear||cls");
    printf("###############################################\n");
    printf("#    L I S T A  D E  V E S T I M E N T A S    #\n");
    printf("###############################################\n");
    printf("#                                             #\n");
    //Exibe lista de vestimentas
    printf("###############################################\n\n");
    printf("Pressione ENTER para continuar ");
    getchar();
}

void tela_relatorio_locacoes(void) {
    system("clear||cls");
    printf("###############################################\n");
    printf("#       L I S T A  D E  L O C A Ç Õ E S       #\n");
    printf("###############################################\n");
    printf("#                                             #\n");
    //Exibe lista de locações
    printf("###############################################\n\n");
    printf("Pressione ENTER para continuar ");
    getchar();
}
