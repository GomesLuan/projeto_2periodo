#include <stdio.h>
#include <stdlib.h>
#include "validacoes.h"
#include "telas_vestimenta.h"
#include "operacoes_gerais.h"

typedef struct vestimenta {
    char id[14];
    char nome[81];
    int num_p;
    int num_m;
    int num_g;
    float preco;
} Vestimenta; 

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

void tela_cadastro_vestimenta(Vestimenta *vest) {
    system("clear||cls");
    //Alocando espaço para a variável
    printf("########################################################\n");
    printf("#      C A D A S T R O   D E   V E S T I M E N T A     #\n");
    printf("########################################################\n");
    printf("# Por favor, informe os dados solicitados:\n");
    cad_nome_vest(vest->nome);
    cad_num_vest(&vest->num_p, 'P');
    cad_num_vest(&vest->num_m, 'M');
    cad_num_vest(&vest->num_g, 'G');
    cad_preco_vest(&vest->preco);
    printf("####################################################\n");
}

void tela_info_vestimenta(Vestimenta *vest) {
    system("clear||cls");
    printf("#################################################################\n");
    printf("#       I N F O R M A Ç Õ E S   D E   V E S T I M E N T A       #\n");
    printf("#################################################################\n");
    printf("#       Número de identificação: %s\n", vest->id);
    printf("#       Nome da vestimenta: %s\n", vest->nome);
    printf("#       Número de unidades de tamanho P: %d\n", vest->num_p);
    printf("#       Número de unidades de tamanho M: %d\n", vest->num_m);
    printf("#       Número de unidades de tamanho G: %d\n", vest->num_g);
    printf("#       Preço da locação diária (R$): %.2f\n", vest->preco);
    printf("#################################################################\n\n");
    printf("Pressione ENTER para continuar ");
    getchar();
}

char tela_alterar_vestimenta(Vestimenta *vest) {
    system("clear||cls");
    char resposta;
    printf("##############################################################\n");
    printf("#    A L T E R A R   D A D O S   D E   V E S T I M E N T A   #\n");
    printf("##############################################################\n");
    printf("#       Qual informação gostaria de alterar?\n");
    printf("#       1 - Nome da vestimenta: (%s)\n", vest->nome);
    printf("#       2 - Número de unidades de tamanho P: (%d)\n", vest->num_p);
    printf("#       3 - Número de unidades de tamanho M: (%d)\n", vest->num_m);
    printf("#       4 - Número de unidades de tamanho G: (%d)\n", vest->num_g);
    printf("#       5 - Preço da locação diária (R$): (%.2f)\n", vest->preco);
    printf("#       0 - Retornar ao menu de vestimentas\n");
    printf("#########################################################\n\n");
    printf("Escolha sua opção: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

char tela_remover_vestimenta(Vestimenta *vest) {
    system("clear||cls");
    char resposta;
    printf("###################################################################\n");
    printf("#            R E M O Ç Ã O   D E   V E S T I M E N T A            #\n");
    printf("###################################################################\n");
    printf("#       Número de identificação: %s\n", vest->id);
    printf("#       Nome da vestimenta: %s\n", vest->nome);
    printf("#       Número de unidades de tamanho P: %d\n", vest->num_p);
    printf("#       Número de unidades de tamanho M: %d\n", vest->num_m);
    printf("#       Número de unidades de tamanho G: %d\n", vest->num_g);
    printf("#       Preço da locação diária (R$): %.2f\n", vest->preco);
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

void cad_nome_vest(char *nome) {
    int nome_valido = 0;
    do {
        printf("# Nome da vestimenta: ");
        scanf("%[A-Z a-z 0-9 .,-_# áéíóúâôãõç ÁÉÍÓÚÂÔÃÕÇ]", nome);
        getchar();
        nome_valido = valida_nome_vest(nome);
        if (!nome_valido) {
            printf("Valor inválido! ");
            getchar();
            printf("\x1b[2K");
            printf("\x1b[1F");
            printf("\x1b[2K");
            printf("\x1b[1F");
            printf("\x1b[2K");
        }
    } while (!nome_valido);
}

void cad_num_vest(int *num, char tam) {
    int num_valido = 0;
    char *num_str = (char*) malloc(5*sizeof(char));
    do {
        printf("# Número de vestimentas de tamanho %c: ", tam);
        scanf("%s", num_str);
        getchar();
        num_valido = valida_inteiro(num_str);
        if (!num_valido) {
            printf("Valor inválido! ");
            getchar();
            printf("\x1b[2K");
            printf("\x1b[1F");
            printf("\x1b[2K");
            printf("\x1b[1F");
            printf("\x1b[2K");
        }
    } while (!num_valido);
    *num = converte_str_para_int(num_str);
    free(num_str);
}

void cad_preco_vest(float *preco) {
    int preco_valido = 0;
    char *preco_str = (char*) malloc(10*sizeof(char));
    do {
        printf("# Preço da locação diária (R$): ");
        scanf("%s", preco_str);
        getchar();
        preco_valido = valida_float(preco_str);
        if (!preco_valido) {
            printf("Valor inválido! ");
            getchar();
            printf("\x1b[2K");
            printf("\x1b[1F");
            printf("\x1b[2K");
            printf("\x1b[1F");
            printf("\x1b[2K");
        }
    } while (!preco_valido);
    *preco = converte_str_para_float(preco_str);
}