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

void tela_info_vestimenta(char *nome, char *num_p, char *num_m, char *num_g, char *preco) {
    system("clear||cls");
    printf("#################################################################\n");
    printf("#       I N F O R M A C O E S   D E   V E S T I M E N T A       #\n");
    printf("#################################################################\n");
    printf("#       Nome de identificacao: %s\n", nome);
    printf("#       Numero de unidades de tamanho P: %s\n", num_p);
    printf("#       Numero de unidades de tamanho M: %s\n", num_m);
    printf("#       Numero de unidades de tamanho G: %s\n", num_g);
    printf("#       Preco da locacao diaria (R$): %s\n", preco);
    printf("#################################################################\n\n");
    printf("Pressione ENTER para continuar ");
    getchar();
}

char tela_alterar_vestimenta(char *num_p, char *num_m, char *num_g, char *preco) {
    system("clear||cls");
    char resposta;
    printf("##############################################################\n");
    printf("#    A L T E R A R   D A D O S   D E   V E S T I M E N T A   #\n");
    printf("##############################################################\n");
    printf("#       Qual informacao gostaria de alterar?\n");
    printf("#       1 - Numero de unidades de tamanho P: (%s)\n", num_p);
    printf("#       2 - Numero de unidades de tamanho M: (%s)\n", num_m);
    printf("#       3 - Numero de unidades de tamanho G: (%s)\n", num_g);
    printf("#       4 - Preco da locacao diaria (R$):(%s)\n", preco);
    printf("#       0 - Retornar ao menu de vestimentas\n");
    printf("#########################################################\n\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}