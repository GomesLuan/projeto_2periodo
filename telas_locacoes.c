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
    printf("#       4 - Cancelar locacao                      #\n");
    printf("#       0 - Retornar ao menu principal            #\n");
    printf("###################################################\n\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

void tela_cadastro_locacao(char **num_id, char **cpf, char **nome_vest, char **data_inicio, char **data_fim) {
    system("clear||cls");
    printf("########################################################\n");
    printf("#          C O N T R A T O   D E   A L U G U E L       #\n");
    printf("########################################################\n");
    printf("# Por favor, informe os dados solicitados:\n");
    printf("# Numero de identificacao da locacao (6 digitos): ");
    scanf("%s", *num_id);
    getchar();
    printf("# CPF do cliente responsavel: ");
    scanf("%s", *cpf);
    getchar();
    printf("# Nome da vestimenta alugada: ");
    scanf("%s", *nome_vest);
    getchar();
    printf("# Data de inicio da locacao (dd/mm/aaaa): ");
    scanf("%s", *data_inicio);
    getchar();
    printf("# Data de fim da locacao (dd/mm/aaaa): ");
    scanf("%s", *data_fim);
    getchar();
    printf("########################################################\n");
}

void tela_info_locacao(char *num_id, char *cpf, char *nome_vest, char *data_inicio, char *data_fim) {
    system("clear||cls");
    printf("#################################################################\n");
    printf("#       I N F O R M A C O E S   D E   L O C A C A O             #\n");
    printf("#################################################################\n");
    printf("#       Numero de identificacao: %s\n", num_id);
    printf("#       CPF do cliente responsavel: %s\n", cpf);
    printf("#       Nome da vestimenta: %s\n", nome_vest);
    printf("#       Data de inicio: %s\n", data_inicio);
    printf("#       Data de fim: %s\n", data_fim);
    printf("#################################################################\n\n");
    printf("Pressione ENTER para continuar ");
    getchar();
}

char tela_alterar_locacao(char *cpf, char *nome_vest, char *data_inicio, char *data_fim) {
    system("clear||cls");
    char resposta;
    printf("##############################################################\n");
    printf("#    A L T E R A R   D A D O S   D E   C O N T R A T O       #\n");
    printf("##############################################################\n");
    printf("#       Qual informacao gostaria de alterar?\n");
    printf("#       1 - CPF do cliente responsavel: (%s)\n", cpf);
    printf("#       2 - Nome da vestimenta alugada: (%s)\n", nome_vest);
    printf("#       3 - Data de inicio da locacao: (%s)\n", data_inicio);
    printf("#       4 - Data de fim da locacao: (%s)\n", data_fim);
    printf("#       0 - Retornar ao menu de locacao\n");
    printf("#########################################################\n\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

char tela_remover_locacao(char *num_id, char *cpf, char *nome_vest, char *data_inicio, char *data_fim) {
      system("clear||cls");
    char resposta;
    printf("#########################################################################\n");
    printf("#            C A N C E L A M E N T O   D E   C O N T R A T O            #\n");
    printf("#########################################################################\n");
    printf("#       Numero de idenficacao da locacao: %s\n", num_id);
    printf("#       CPF do cliente responsavel: %s\n", cpf);
    printf("#       Nome da vestimenta alugada: %s\n", nome_vest);
    printf("#       Data de inicio da locacao: %s\n", data_inicio);
    printf("#       Data de fim da locacao: %s\n", data_fim);
    printf("#\n");
    printf("#       Tem certeza que deseja cancelar o contrato?\n");
    printf("#       1 - Sim\n");
    printf("#       2 - Nao \n");
    printf("#########################################################################\n\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}