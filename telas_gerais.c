#include <stdio.h>
#include <stdlib.h>

char tela_principal(void) {
    system("clear||cls");
    char resposta;
    printf("#########################################\n");
    printf("#      M E N U   P R I N C I P A L      #\n");
    printf("#########################################\n");
    printf("#       1 - Clientes                    #\n");
    printf("#       2 - Vestimentas                 #\n");
    printf("#       3 - Locações                    #\n");
    printf("#       4 - Relatórios                  #\n");
    printf("#       5 - Informações do Projeto      #\n");
    printf("#       6 - Orientações                 #\n");
    printf("#       0 - Sair do Programa            #\n");
    printf("#########################################\n\n");
    printf("Escolha sua opção: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

void tela_informacoes(void) {
    system("clear||cls");
    printf("###############################################################################\n");
    printf("#                            I N F O R M A Ç Õ E S                            #\n");
    printf("###############################################################################\n");
    printf("# Programa desenvolvido inteiramente em C com o intuito de facilitar a        #\n");
    printf("# administração e gerência de uma locadora de roupas e fantasias.             #\n");
    printf("# Identificando os produtos disponíveis, os valores dos aluguéis, o tempo, a  #\n");
    printf("# identidade de quem alugou e quantas vezes determinada peça foi alugada,     #\n");
    printf("# sendo uma ferramenta útil e eficaz.                                         #\n");
    printf("#                                                                             #\n");
    printf("# Programa desenvolvido por:                                                  #\n");
    printf("#                                                                             #\n");
    printf("# Laety Maniery de Araujo Batista                                             #\n");
    printf("# E-mail: powermaniere@gmail.com                                              #\n");
    printf("#                                                                             #\n");
    printf("# Luan Victor de Araujo Gomes                                                 #\n");
    printf("# E-mail: luan.araujo.gom@gmail.com                                           #\n");
    printf("###############################################################################\n\n");
    printf("Pressione ENTER para continuar ");
    getchar();
}

void tela_orientacoes(void) {
    system("clear||cls");
    printf("##############################################################################\n");
    printf("#                            O R I E N T A Ç Õ E S                           #\n");
    printf("##############################################################################\n");
    printf("# Menu Clientes: Cadastro, consulta e remoção de clientes.                   #\n");
    printf("# Menu Roupas e Fantasias: Adição, informações e remoção de vestimentas.     #\n");
    printf("# Menu Locações: Agendamento, verificação e cancelamento de locações.        #\n");
    printf("# Menu Relatório: Informações de todos os clientes e vestimentas e locações. #\n");
    printf("# Menu Informações do projeto: Informações gerais do projeto e equipe        #\n");
    printf("##############################################################################\n\n");
    printf("Pressione ENTER para continuar ");
    getchar();
}