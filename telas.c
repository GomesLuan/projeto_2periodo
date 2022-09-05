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

char **tela_cadastro_cliente() {
    limpar_tela();
    //Alocando espaço para a variável
    char **informacoes = malloc(5* sizeof(char*));
    for (int i=0; i < 10; ++i) {
        informacoes[i] = malloc(50* sizeof(char));
    }
    printf("####################################################\n");
    printf("#     C A D A S T R O   D E   C L I E N T E S      #\n");
    printf("####################################################\n\n");
    printf("Por favor, informe os dados solicitados:\n\n");
    printf("Nome: ");
    scanf("%s", informacoes[0]);
    printf("CPF (apenas numeros): ");
    scanf("%s", informacoes[1]);
    printf("Data de nascimento (dd/mm/aaaa): ");
    scanf("%s", informacoes[2]);
    printf("Telefone para contato: ");
    scanf("%s", informacoes[3]);
    printf("E-mail para contato: ");
    scanf("%s", informacoes[4]);
    printf("\n####################################################\n\n");
    getchar();
    return informacoes;
}
char tela_clientes_info(void) {
    limpar_tela();
    char resposta;
    printf("#########################################\n");
    printf("#       INFORMACOES DOS CLIENTES        #\n");
    printf("#########################################\n");
    printf("#       Nome:informacoes[0]             #\n");
    printf("#       CPF:informacoes[1]              #\n");
    printf("#       Nascimento:informacoes[2]       #\n");
    printf("#       Telefone:informacoes[3]         #\n");
    printf("#       E-Mail: informacoes[4]          #\n");
    printf("#                                       #\n");
    printf("#       0 - Voltar ao menu              #\n");
    printf("#########################################\n\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &resposta);
    getchar();
    return informacoes;
}

char **tela_alterar_dados_dos_clientes() {
    limpar_tela();
    //Alocando espaço para a variável
    char **informacoes = malloc(5* sizeof(char*));
    for (int i=0; i < 10; ++i) {
        informacoes[i] = malloc(50* sizeof(char));
    }
    printf("####################################################\n");
    printf("#         ALTERAR INFORMACOES DOS CLIENTES         #\n");
    printf("####################################################\n\n");
    printf("Por favor, informe os dados solicitados:\n\n");
    printf("Nome: ");
    scanf("%s", informacoes[0]);
    printf("CPF (apenas numeros): ");
    scanf("%s", informacoes[1]);
    printf("Data de nascimento (dd/mm/aaaa): ");
    scanf("%s", informacoes[2]);
    printf("Telefone para contato: ");
    scanf("%s", informacoes[3]);
    printf("E-mail para contato: ");
    scanf("%s", informacoes[4]);
    printf("\n####################################################\n\n");
    getchar();
    return informacoes;

char tela_remover_cliente(void) {
    limpar_tela();
    char resposta;
    printf("#########################################\n");
    printf("#         EXCLUSAO DE CLIENTES          #\n");
    printf("#########################################\n");
    printf("#       INFORME O CPF DO CLIENTE        #\n");
    printf("#                                       #\n");
    printf("#              CPF:                     #\n");
    printf("#                                       #\n");
    printf("#                                       #\n");
    printf("#                                       #\n");
    printf("#       0 - Voltar ao menu              #\n");
    printf("#########################################\n\n");
    printf("Escolha sua opcao: ");
    scanf("%s", informacoes[0]);
    printf("CPF (apenas numeros): ");
    scanf("%c", &resposta);
    getchar();
    return informacoes[1];
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


