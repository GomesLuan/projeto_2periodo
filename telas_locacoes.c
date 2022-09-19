#include <stdio.h>
#include <stdlib.h>

char tela_locacoes(void) {
    system("clear||cls");
    char resposta;
    printf("###################################################\n");
    printf("#           M E N U   D E   L O C A C O E S       #\n");
    printf("###################################################\n");
    printf("#       1 - Contratar locacao                     #\n");
    printf("#       2 - Informacoes de locacao                #\n");
    printf("#       3 - Alterar dados da locacoes             #\n");
    printf("#       4 - Remover locacao                       #\n");
    printf("#       0 - Retornar ao menu principal            #\n");
    printf("###################################################\n\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

char **tela_cadastro_info_locacao(void) {
    system("clear||cls");
    //Alocando espaço para a variável
    char **informacoes = malloc(3* sizeof(char*));
    for (int i=0; i < 3; ++i) {
        informacoes[i] = malloc(50* sizeof(char));
    }
    printf("########################################################\n");
    printf("#          C O N T R A T O   D E   A L U G U E L       #\n");
    printf("########################################################\n");
    printf("# Por favor, informe os dados solicitados:\n");
    printf("# Nome de identificacao: ");
    scanf("%s", informacoes[0]);
    getchar();
    printf("# Valor da diaria: ");
    scanf("%s", informacoes[1]);
    getchar();
    printf("# Quantidade de dias: ");
    scanf("%s", informacoes[2]);
    getchar();
    printf("####################################################\n");
    return informacoes;
}

void tela_info_locacao(char *nome, char *num_dias, char *preco) {
    system("clear||cls");
    printf("#################################################################\n");
    printf("#       I N F O R M A C O E S   D E   L O C A C A O             #\n");
    printf("#################################################################\n");
    printf("#       Nome de identificacao: %s\n", nome);
    printf("#       Quantidade de dias: %s\n", num_dias);
    printf("#       Preco da locacao diaria (R$): %s\n", preco);
    printf("#################################################################\n\n");
    printf("Pressione ENTER para continuar ");
    getchar();
}

char tela_alterar_locacao(char *nome, char *num_dias, char *preco) {
    system("clear||cls");
    char resposta;
    printf("##############################################################\n");
    printf("#    A L T E R A R   D A D O S   D E   C O N T R A T O       #\n");
    printf("##############################################################\n");
    printf("#       Qual informacao gostaria de alterar?\n");
    printf("#       1 - Nome: (%s)\n", nome);
    printf("#       2 - Quantidade de dias: (%s)\n", num_dias);
    printf("#       2 - Preco da locacao diaria (R$): (%s)\n", preco);
    printf("#       0 - Retornar ao menu de locacao\n");
    printf("#########################################################\n\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

char tela_remover_locacao(char *nome, char *num_dias, char *preco) {
      system("clear||cls");
    char resposta;
    printf("###################################################################\n");
    printf("#            R E M O C A O   D E   C O N T R A T O                #\n");
    printf("###################################################################\n");
    printf("#       Nome de identificação: %s\n", nome);
    printf("#       Quantidade de dias: %s\n", num_dias);
    printf("#       Preco da locacao diaria (R$): %s\n", preco);
    printf("#\n");
    printf("#       Tem certeza que deseja remover o contrato?\n");
    printf("#       1 - Sim\n");
    printf("#       2 - Nao \n");
    printf("#############################################################\n\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}