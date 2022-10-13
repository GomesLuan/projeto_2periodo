#include <stdio.h>
#include <stdlib.h>

char tela_locacoes(void) {
    system("clear||cls");
    char resposta;
    printf("###################################################\n");
    printf("#           M E N U   D E   L O C A Ç Õ E S       #\n");
    printf("###################################################\n");
    printf("#       1 - Agendar locação                       #\n");
    printf("#       2 - Informações de locação                #\n");
    printf("#       3 - Alterar dados da locação              #\n");
    printf("#       4 - Cancelar agendamento                  #\n");
    printf("#       5 - Receber produto alugado               #\n");
    printf("#       6 - Devolver produto alugado              #\n");
    printf("#       0 - Retornar ao menu principal            #\n");
    printf("###################################################\n\n");
    printf("Escolha sua opção: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

void tela_cadastro_locacao(char *num_id, char *cpf, char *nome_vest, char *tam_vest, char *data_inicio, char *data_fim) {
    system("clear||cls");
    printf("###########################################################\n");
    printf("#       A G E N D A M E N T O   D E   L O C A Ç Ã O       #\n");
    printf("###########################################################\n");
    printf("# Por favor, informe os dados solicitados:\n");
    printf("# Número de identificação da locação (6 dígitos): ");
    scanf("%s", num_id);
    getchar();
    printf("# CPF do cliente responsável: ");
    scanf("%s", cpf);
    getchar();
    printf("# Nome da vestimenta alugada: ");
    scanf("%s", nome_vest);
    getchar();
    printf("# Tamanho da vestimenta alugada (P/M/G): ");
    scanf("%s", tam_vest);
    getchar();
    printf("# Data de início da locação (dd/mm/aaaa): ");
    scanf("%s", data_inicio);
    getchar();
    printf("# Data de fim da locação (dd/mm/aaaa): ");
    scanf("%s", data_fim);
    getchar();
    printf("########################################################\n");
}

void tela_info_locacao(char *num_id, char *cpf, char *nome_vest, char *tam_vest, char *data_inicio, char *data_fim) {
    system("clear||cls");
    printf("#################################################################\n");
    printf("#       I N F O R M A Ç Õ E S   D E   L O C A Ç Ã O             #\n");
    printf("#################################################################\n");
    printf("#       Numero de identificação: %s\n", num_id);
    printf("#       CPF do cliente responsável: %s\n", cpf);
    printf("#       Nome da vestimenta: %s\n", nome_vest);
    printf("#       Tamanho da vestimenta: %s\n", tam_vest);
    printf("#       Data de início: %s\n", data_inicio);
    printf("#       Data de fim: %s\n", data_fim);
    printf("#################################################################\n\n");
    printf("Pressione ENTER para continuar ");
    getchar();
}

char tela_alterar_locacao(char *cpf, char *nome_vest, char *tam_vest, char *data_inicio, char *data_fim) {
    system("clear||cls");
    char resposta;
    printf("##############################################################\n");
    printf("#       A L T E R A R   D A D O S   D E   L O C A ÇÃ O       #\n");
    printf("##############################################################\n");
    printf("#       Qual informação gostaria de alterar?\n");
    printf("#       1 - CPF do cliente responsável: (%s)\n", cpf);
    printf("#       2 - Nome da vestimenta alugada: (%s)\n", nome_vest);
    printf("#       3 - Tamanho da vestimenta alugada: (%s)\n", tam_vest);
    printf("#       4 - Data de início da locação: (%s)\n", data_inicio);
    printf("#       5 - Data de fim da locação: (%s)\n", data_fim);
    printf("#       0 - Retornar ao menu de locação\n");
    printf("#########################################################\n\n");
    printf("Escolha sua opção: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

char tela_remover_locacao(char *num_id, char *cpf, char *nome_vest, char *tam_vest, char *data_inicio, char *data_fim) {
    system("clear||cls");
    char resposta;
    printf("#########################################################################\n");
    printf("#             C A N C E L A M E N T O   D E   L O C A Ç Ã O             #\n");
    printf("#########################################################################\n");
    printf("#       Número de idenficação da locação: %s\n", num_id);
    printf("#       CPF do cliente responsável: %s\n", cpf);
    printf("#       Nome da vestimenta alugada: %s\n", nome_vest);
    printf("#       Tamanho da vestimenta alugada: %s\n", tam_vest);
    printf("#       Data de início da locação: %s\n", data_inicio);
    printf("#       Data de fim da locação: %s\n", data_fim);
    printf("#\n");
    printf("#       Tem certeza que deseja cancelar este agendamento?\n");
    printf("#       1 - Sim\n");
    printf("#       2 - Não \n");
    printf("#########################################################################\n\n");
    printf("Escolha sua opção: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

char tela_receber_produto(char *num_id, char *cpf, char *nome_vest, char *tam_vest, char *data_inicio, char *data_fim) {
    system("clear||cls");
    char resposta;
    printf("#######################################################################\n");
    printf("#             R E C E B I M E N T O   D E   P R O D U T O             #\n");
    printf("#######################################################################\n");
    printf("#       Número de idenficação da locação: %s\n", num_id);
    printf("#       CPF do cliente responsável: %s\n", cpf);
    printf("#       Nome da vestimenta alugada: %s\n", nome_vest);
    printf("#       Tamanho da vestimenta alugada: %s\n", tam_vest);
    printf("#       Data de início da locação: %s\n", data_inicio);
    printf("#       Data de fim da locação: %s\n", data_fim);
    printf("#\n");
    printf("#       Deseja confirmar o recebimento do produto desta locação?\n");
    printf("#       1 - Sim\n");
    printf("#       2 - Não \n");
    printf("#######################################################################\n\n");
    printf("Escolha sua opção: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

char tela_devolver_produto(char *num_id, char *cpf, char *nome_vest, char *tam_vest, char *data_inicio, char *data_fim) {
    system("clear||cls");
    char resposta;
    printf("####################################################################\n");
    printf("#             D E V O L U Ç Ã O   D E   P R O D U T O              #\n");
    printf("####################################################################\n");
    printf("#       Número de idenficação da locação: %s\n", num_id);
    printf("#       CPF do cliente responsável: %s\n", cpf);
    printf("#       Nome da vestimenta alugada: %s\n", nome_vest);
    printf("#       Tamanho da vestimenta alugada: %s\n", tam_vest);
    printf("#       Data de início da locação: %s\n", data_inicio);
    printf("#       Data de fim da locação: %s\n", data_fim);
    printf("#\n");
    printf("#       Deseja confirmar a devolução do produto desta locação?\n");
    printf("#       1 - Sim\n");
    printf("#       2 - Não \n");
    printf("####################################################################\n\n");
    printf("Escolha sua opção: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}