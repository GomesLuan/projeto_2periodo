#include <stdio.h>
#include <stdlib.h>
#include "op_sistema.c"

char tela_principal(void) {
    limpar_tela();
    char resposta;
    printf("#########################################\n");
    printf("#      M E N U   P R I N C I P A L      #\n");
    printf("#########################################\n");
    printf("#       1 - Clientes                    #\n");
    printf("#       2 - Roupas e Fantasias          #\n");
    printf("#       3 - Locacoes                    #\n");
    printf("#       4 - Relatorios                  #\n");
    printf("#       5 - Informacoes do Projeto      #\n");
    printf("#       6 - Orientacoes                 #\n");
    printf("#       0 - Sair do Programa            #\n");
    printf("#########################################\n\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

char tela_clientes(void) {
    limpar_tela();
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
    limpar_tela();
    //Alocando espaço para a variável
    char **informacoes = malloc(5* sizeof(char*));
    for (int i=0; i < 10; ++i) {
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
void tela_info_cliente(/*char *nome, char *cpf, char *nascimento, char *telefone, char *email*/) {
    limpar_tela();
    printf("###########################################################\n");
    printf("#       I N F O R M A C O E S   D E   C L I E N T E       #\n");
    printf("###########################################################\n");
    printf("#       Nome:                                             #\n");
    printf("#       CPF:                                              #\n");
    printf("#       Data de nascimento:                               #\n");
    printf("#       Telefone:                                         #\n");
    printf("#       E-Mail:                                           #\n");
    printf("###########################################################\n\n");
    pausar_sistema();
}

char tela_alterar_cliente(/*char *nome, char *cpf, char *nascimento, char *telefone, char *email*/) {
    limpar_tela();
    char resposta;
    printf("#########################################################\n");
    printf("#    A L T E R A R   D A D O S   D E   C L I E N T E    #\n");
    printf("#########################################################\n");
    printf("#       Qual informacao gostaria de alterar?            #\n");
    printf("#       1 - Nome ()                                     #\n");
    printf("#       2 - Data de nascimento ()                       #\n");
    printf("#       3 - Telefone ()                                 #\n");
    printf("#       4 - E-mail ()                                   #\n");
    printf("#       0 - Retornar ao menu de clientes                #\n");
    printf("#########################################################\n\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

char tela_remover_cliente(/*char *nome, char *cpf, char *nascimento, char *telefone, char *email*/) {
    limpar_tela();
    char resposta;
    printf("#############################################################\n");
    printf("#            R E M O C A O   D E   C L I E N T E            #\n");
    printf("#############################################################\n");
    printf("#       Nome:                                               #\n");
    printf("#       CPF:                                                #\n");
    printf("#       Data de nascimento:                                 #\n");
    printf("#       Telefone:                                           #\n");
    printf("#       E-Mail:                                             #\n");
    printf("#                                                           #\n");
    printf("#       Tem certeza que deseja remover este cliente?        #\n");
    printf("#       1 - Sim                                             #\n");
    printf("#       2 - Nao                                             #\n");
    printf("#############################################################\n\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

void tela_informacoes(void) {
    limpar_tela();
    printf("###############################################################################\n");
    printf("#                            I N F O R M A C O E S                            #\n");
    printf("###############################################################################\n");
    printf("# Programa desenvolvido inteiramente em C com o intuito de facilitar a        #\n");
    printf("# administracao e gerencia de uma locadora de roupas e fantasias.             #\n");
    printf("# Identificando os produtos disponiveis, os valores dos alugueis, o tempo, a  #\n");
    printf("# identidade de quem alugou e quantas vezes determinada peca foi alugada,     #\n");
    printf("# sendo uma ferramenta util e eficaz.                                         #\n");
    printf("#                                                                             #\n");
    printf("# Programa desenvolvido por:                                                  #\n");
    printf("#                                                                             #\n");
    printf("# Laety Maniery de Araujo Batista                                             #\n");
    printf("# E-mail: powermaniere@gmail.com                                              #\n");
    printf("#                                                                             #\n");
    printf("# Luan Victor de Araujo Gomes                                                 #\n");
    printf("# E-mail: luan.araujo.gom@gmail.com                                           #\n");
    printf("###############################################################################\n\n");
    pausar_sistema();
}

void tela_orientacoes(void) {
    limpar_tela();
    printf("###################################################################################################\n");
    printf("#                                      O R I E N T A C O E S                                      #\n");
    printf("###################################################################################################\n");
    printf("# Menu Clientes: Cadastro, consulta e remocao de clientes.                                        #\n");
    printf("# Menu Roupas e Fantasias: Adicao, informacoes e remocao de vestimentas.                          #\n");
    printf("# Menu Locacoes: Agendamento, verificacao e cancelamento de locacoes.                             #\n");
    printf("# Menu Relatorio: Informacoes de todos os clientes e vestimentas, alem do historico de locacoes.  #\n");
    printf("# Menu Informacoes do projeto: Exibe informacoes gerais do projeto e a equipe de desenvolvedores. #\n");
    printf("###################################################################################################\n\n");
    pausar_sistema();
}


