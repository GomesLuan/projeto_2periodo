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
    printf("#       5 - Sobre                       #\n");
    printf("#       6 - Ajuda                       #\n");
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
    printf("# No menu clientes ira realizar o cadastro, encontrar contato e exlusao dos clientes.             #\n");
    printf("# No menu roupas e fantasias irá fazer o aluguel, ver os que foram alugados e por quanto tempo.   #\n");
    printf("# No menu locacoes encontrara os valores do aluguel e por quem foi alugado.                       #\n");
    printf("# No menu relatorio esta o historico dos alugueis e a quantidade de vezes que cada cliente alugou.#\n");
    printf("# No Menu sobre, tem as descricoes de cada fantasia ou roupa assim como as opcoes disponiveis.    #\n");
    printf("# No menu orientacoes descreve oque cada opcao faz                                                #\n");
    printf("#                                       0 - Menu Principal                                        #\n");
    printf("###################################################################################################\n\n");
    printf("Escolha sua opcao: ");
    scanf("%c", &resposta);
    return resposta;
}
