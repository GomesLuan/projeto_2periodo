#include <stdio.h>
#include <stdlib.h>

char tela_vestimentas(void) {
    system("clear||cls");
    char resposta;
    printf("###################################################\n");
    printf("#      M E N U   D E   V E S T I M E N T A S      #\n");
    printf("###################################################\n");
    printf("#       1 - Cadastrar vestimenta                  #\n");
    printf("#       2 - Informacoes de vestimenta             #\n");
    printf("#       3 - Alterar dados de vestimenta           #\n");
    printf("#       4 - Remover vestimenta                    #\n");
    printf("#       0 - Retornar ao menu principal            #\n");
    printf("###################################################\n\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

char **tela_cadastro_vestimenta(void) {
    system("clear||cls");
    //Alocando espaço para a variável
    char **informacoes = malloc(5* sizeof(char*));
    for (int i=0; i < 5; ++i) {
        informacoes[i] = malloc(50* sizeof(char));
    }
    printf("########################################################\n");
    printf("#      C A D A S T R O   D E   V E S T I M E N T A     #\n");
    printf("########################################################\n");
    printf("# Por favor, informe os dados solicitados:\n");
    printf("# Nome de identificacao: ");
    scanf("%s", informacoes[0]);
    getchar();
    printf("# Numero de unidades de tamanho P: ");
    scanf("%s", informacoes[1]);
    getchar();
    printf("# Numero de unidades de tamanho M: ");
    scanf("%s", informacoes[2]);
    getchar();
    printf("# Numero de unidades de tamanho G: ");
    scanf("%s", informacoes[3]);
    getchar();
    printf("# Preco da locacao diaria (R$): ");
    scanf("%s", informacoes[4]);
    getchar();
    printf("####################################################\n");
    return informacoes;
}