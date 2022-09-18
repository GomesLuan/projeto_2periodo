#include <stdio.h>
#include <stdlib.h>

char tela_locacoes(void) {
    system("clear||cls");
    char resposta;
    printf("###################################################\n");
    printf("#           M E N U   D E   L O C A C O E S       #\n");
    printf("###################################################\n");
    printf("#       1 - Cadastrar locacoes                    #\n");
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