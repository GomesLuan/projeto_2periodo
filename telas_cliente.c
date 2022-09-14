#include <stdio.h>
#include <stdlib.h>

char tela_clientes(void) {
    system("clear||cls");
    char resposta;
    printf("#########################################\n");
    printf("#    M E N U   D E   C L I E N T E S    #\n");
    printf("#########################################\n");
    printf("#       1 - Cadastrar cliente           #\n");
    printf("#       2 - Informacoes de cliente      #\n");
    printf("#       3 - Alterar dados de cliente    #\n");
    printf("#       4 - Remover cliente             #\n");
    printf("#       0 - Retornar ao menu principal  #\n");
    printf("#########################################\n\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

char **tela_cadastro_cliente(void) {
    system("clear||cls");
    //Alocando espaço para a variável
    char **informacoes = malloc(5* sizeof(char*));
    for (int i=0; i < 5; ++i) {
        informacoes[i] = malloc(50* sizeof(char));
    }
    printf("####################################################\n");
    printf("#     C A D A S T R O   D E   C L I E N T E S      #\n");
    printf("####################################################\n");
    printf("# Por favor, informe os dados solicitados:\n");
    printf("# Nome: ");
    scanf("%s", informacoes[0]);
    getchar();
    printf("# CPF (apenas numeros): ");
    scanf("%s", informacoes[1]);
    getchar();
    printf("# Data de nascimento (dd/mm/aaaa): ");
    scanf("%s", informacoes[2]);
    getchar();
    printf("# Telefone para contato: ");
    scanf("%s", informacoes[3]);
    getchar();
    printf("# E-mail para contato: ");
    scanf("%s", informacoes[4]);
    getchar();
    return informacoes;
}
void tela_info_cliente(char *nome, char *cpf, char *nascimento, char *telefone, char *email) {
    system("clear||cls");
    printf("###########################################################\n");
    printf("#       I N F O R M A C O E S   D E   C L I E N T E       #\n");
    printf("###########################################################\n");
    printf("#       Nome: %s\n", nome);
    printf("#       CPF: %s\n", cpf);
    printf("#       Data de nascimento: %s\n", nascimento);
    printf("#       Telefone: %s\n", telefone);
    printf("#       E-Mail: %s\n", email);
    printf("###########################################################\n\n");
    system("pause||read -p \"Pressione ENTER para continuar \" saindo");
}

char tela_alterar_cliente(char *nome, char *nascimento, char *telefone, char *email) {
    system("clear||cls");
    char resposta;
    printf("#########################################################\n");
    printf("#    A L T E R A R   D A D O S   D E   C L I E N T E    #\n");
    printf("#########################################################\n");
    printf("#       Qual informacao gostaria de alterar?\n");
    printf("#       1 - Nome (%s)\n", nome);
    printf("#       2 - Data de nascimento (%s)\n", nascimento);
    printf("#       3 - Telefone (%s)\n", telefone);
    printf("#       4 - E-mail (%s)\n", email);
    printf("#       0 - Retornar ao menu de clientes\n");
    printf("#########################################################\n\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

char tela_remover_cliente(char *nome, char *cpf, char *nascimento, char *telefone, char *email) {
    system("clear||cls");
    char resposta;
    printf("#############################################################\n");
    printf("#            R E M O C A O   D E   C L I E N T E            #\n");
    printf("#############################################################\n");
    printf("#       Nome: %s\n", nome);
    printf("#       CPF: %s\n", cpf);
    printf("#       Data de nascimento: %s\n", nascimento);
    printf("#       Telefone: %s\n", telefone);
    printf("#       E-Mail: %s\n", email);
    printf("#\n");
    printf("#       Tem certeza que deseja remover este cliente?\n");
    printf("#       1 - Sim\n");
    printf("#       2 - Nao \n");
    printf("#############################################################\n\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}