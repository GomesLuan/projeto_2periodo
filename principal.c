#include <stdio.h>
#include "operacoes_cliente.h"
#include "telas_cliente.h"
#include "telas_gerais.h"

int main(void) {
    //Inicio do programa
    char resposta_principal = '1';
    while (resposta_principal != '0') {
        resposta_principal = tela_principal();
        char resposta_clientes = '1';
        //char resposta_roupas;
        //char resposta_locacoes;
        //char resposta_relatorios;
        if (resposta_principal == '1') {
            while (resposta_clientes != '0') {
                resposta_clientes = tela_clientes();
                if (resposta_clientes == '1') {
                    cadastrar_cliente();
                }
                else if (resposta_clientes == '2') {
                    info_cliente();
                }
                else if (resposta_clientes == '3') {
                    alterar_cliente();
                }
                else if (resposta_clientes == '4') {
                    remover_cliente();
                } 
                else if (resposta_clientes != '0') {
                    printf("\nResposta invalida!\n\n");
                    printf("Pressione ENTER para continuar ");
                    getchar();
                }
            }
        }
        else if (resposta_principal == '5') {
            tela_informacoes();
        }
        else if (resposta_principal == '6') {
            tela_orientacoes();
        }  
        else if (resposta_principal != '0') {
            printf("\nResposta invalida!\n\n");
            printf("Pressione ENTER para continuar ");
            getchar();
        }
    }
    return 0;
}