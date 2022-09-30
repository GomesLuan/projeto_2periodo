#include <stdio.h>
#include <stdlib.h>

char tela_vestimentas(void) {
    system("clear||cls");
    char resposta;
    printf("###################################################\n");
    printf("#      M E N U   D E   V E S T I M E N T A S      #\n");
    printf("###################################################\n");
    printf("#       1 - Cadastrar vestimenta                  #\n");
    printf("#       2 - Informações de vestimenta             #\n");
    printf("#       3 - Alterar dados de vestimenta           #\n");
    printf("#       4 - Remover vestimenta                    #\n");
    printf("#       0 - Retornar ao menu principal            #\n");
    printf("###################################################\n\n");
    printf("Escolha sua opção: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

void tela_cadastro_vestimenta(char **num_id, char **nome, char **num_p, char **num_m, char **num_g, char **preco) {
    system("clear||cls");
    //Alocando espaço para a variável
    printf("########################################################\n");
    printf("#      C A D A S T R O   D E   V E S T I M E N T A     #\n");
    printf("########################################################\n");
    printf("# Por favor, informe os dados solicitados:\n");
    printf("# Número de identificação da vestimenta (6 dígitos): ");
    scanf("%s", *num_id);
    printf("# Nome da vestimenta: ");
    scanf("%s", *nome);
    getchar();
    printf("# Número de unidades de tamanho P: ");
    scanf("%s", *num_p);
    getchar();
    printf("# Número de unidades de tamanho M: ");
    scanf("%s", *num_m);
    getchar();
    printf("# Número de unidades de tamanho G: ");
    scanf("%s", *num_g);
    getchar();
    printf("# Preço da locação diária (R$): ");
    scanf("%s", *preco);
    getchar();
    printf("####################################################\n");
}

void tela_info_vestimenta(char *num_id, char *nome, char *num_p, char *num_m, char *num_g, char *preco) {
    system("clear||cls");
    printf("#################################################################\n");
    printf("#       I N F O R M A Ç Õ E S   D E   V E S T I M E N T A       #\n");
    printf("#################################################################\n");
    printf("#       Número de identificação: %s\n", num_id);
    printf("#       Nome da vestimenta: %s\n", nome);
    printf("#       Número de unidades de tamanho P: %s\n", num_p);
    printf("#       Número de unidades de tamanho M: %s\n", num_m);
    printf("#       Número de unidades de tamanho G: %s\n", num_g);
    printf("#       Preço da locação diária (R$): %s\n", preco);
    printf("#################################################################\n\n");
    printf("Pressione ENTER para continuar ");
    getchar();
}

char tela_alterar_vestimenta(char *nome, char *num_p, char *num_m, char *num_g, char *preco) {
    system("clear||cls");
    char resposta;
    printf("##############################################################\n");
    printf("#    A L T E R A R   D A D O S   D E   V E S T I M E N T A   #\n");
    printf("##############################################################\n");
    printf("#       Qual informação gostaria de alterar?\n");
    printf("#       1 - Nome da vestimenta: (%s)\n", nome);
    printf("#       2 - Número de unidades de tamanho P: (%s)\n", num_p);
    printf("#       3 - Número de unidades de tamanho M: (%s)\n", num_m);
    printf("#       4 - Número de unidades de tamanho G: (%s)\n", num_g);
    printf("#       5 - Preço da locação diária (R$): (%s)\n", preco);
    printf("#       0 - Retornar ao menu de vestimentas\n");
    printf("#########################################################\n\n");
    printf("Escolha sua opção: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

char tela_remover_vestimenta(char *num_id, char *nome, char *num_p, char *num_m, char *num_g, char *preco) {
    system("clear||cls");
    char resposta;
    printf("###################################################################\n");
    printf("#            R E M O Ç Ã O   D E   V E S T I M E N T A            #\n");
    printf("###################################################################\n");
    printf("#       Número de identificação: %s\n", num_id);
    printf("#       Nome da vestimenta: %s\n", nome);
    printf("#       Número de unidades de tamanho P: %s\n", num_p);
    printf("#       Número de unidades de tamanho M: %s\n", num_m);
    printf("#       Número de unidades de tamanho G: %s\n", num_g);
    printf("#       Preço da locação diária (R$): %s\n", preco);
    printf("#\n");
    printf("#       Tem certeza que deseja remover esta vestimenta?\n");
    printf("#       1 - Sim\n");
    printf("#       2 - Não \n");
    printf("#############################################################\n\n");
    printf("Escolha sua opção: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}