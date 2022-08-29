#include <stdio.h>

char tela_principal(void) {
    char resposta;
    printf("\n");
    printf("#########################################\n");
    printf("#      M E N U   P R I N C I P A L      #\n");
    printf("#########################################\n");
    printf("#       1 - Clientes                    #\n");
    printf("#       2 - Roupas e Fantasias          #\n");
    printf("#       3 - Locacoes                    #\n");
    printf("#       4 - Relatorios                  #\n");
    printf("#       5 - Informacoes do Projeto      #\n");
    printf("#       6 - Orientações                 #\n");
    printf("#       0 - Sair do Programa            #\n");
    printf("#########################################\n\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &resposta);
    return resposta;
}

char tela_orientacoes(void) {
    char resposta;
    printf("\n");
    printf("###################################################################################################\n");
    printf("#                                            Orientacoes                                          #\n");
    printf("###################################################################################################\n");
    printf("# Menu Clientes: Cadastro, consulta e remocao de clientes.                                        #\n");
    printf("# Menu Roupas e Fantasias: Adicao, informacoes e remocao de vestimentas.                          #\n");
    printf("# Menu Locacoes: Agendamento, verificacao e cancelamento de locacoes.                             #\n");
    printf("# Menu Relatorio: Informacoes de todos os clientes e vestimentas, alem do historico de locacoes.  #\n");
    printf("# Menu Informacoes do projeto: Exibe informacoes gerais do projeto e a equipe de desenvolvedores. #\n");
    printf("#                                       0 - Menu Principal                                        #\n");
    printf("###################################################################################################\n\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &resposta);
    return resposta;
}

char tela_informacoes(void) {
    char resposta;
    printf("\n");
    printf("###############################################################################\n");
    printf("#                                   Informacoes                               #\n");
    printf("###############################################################################\n");
    printf("# Programa de locadora de roupas e fantasias, desenvolvido inteiramente em C  #\n");
    printf("# Com o intuito de facilitar a administracao e gerencia desse estabelecimento #\n");
    printf("# Identificando as roupas ou fantasias disponiveis, os valores dos alugueis   #\n");
    printf("# O tempo, a identificacao de quem alugou e quantas vezes determinada peca foi#\n");
    printf("# alugada, sendo uma ferramenta util e eficaz.                                #\n");
    printf("###############################################################################\n\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &resposta);
    return resposta;
}
