#include <stdio.h>
#include "operacoes_cliente.h"
#include "operacoes_vestimenta.h"
#include "operacoes_locacao.h"
#include "telas_relatorio.h"
#include "telas_cliente.h"
#include "telas_gerais.h"
#include "telas_vestimenta.h"
#include "telas_locacoes.h"

int main(void) {
    //Inicio do programa
    char resposta_principal = '1';
    while (resposta_principal != '0') {
        resposta_principal = tela_principal();
        char resposta_clientes = '1';
        char resposta_vestimentas = '1';
        char resposta_locacoes = '1';
        char resposta_relatorios = '1';
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
        else if (resposta_principal == '2') {
            while (resposta_vestimentas != '0') {
                resposta_vestimentas = tela_vestimentas();
                if (resposta_vestimentas == '1') {
                    cadastrar_vestimenta();
                }
                else if (resposta_vestimentas == '2') {
                    info_vestimenta();
                }
                else if (resposta_vestimentas == '3') {
                    alterar_vestimenta();
                }
                else if (resposta_vestimentas == '4') {
                    remover_vestimenta();
                } 
                else if (resposta_vestimentas != '0') {
                    printf("\nResposta invalida!\n\n");
                    printf("Pressione ENTER para continuar ");
                    getchar();
                }
            }
        }
        else if (resposta_principal == '3') {
            while (resposta_locacoes != '0') {
                resposta_locacoes = tela_locacoes();
                if (resposta_locacoes == '1') {
                    cadastrar_locacao();
                }
                else if (resposta_locacoes == '2') {
                    info_locacao();
                }
                else if (resposta_locacoes == '3') {
                    alterar_locacao();
                }
                else if (resposta_locacoes== '4') {
                    remover_locacao();
                } 
                else if (resposta_locacoes != '0') {
                    printf("\nResposta invalida!\n\n");
                    printf("Pressione ENTER para continuar ");
                    getchar();
                }
            }
        }
        else if (resposta_principal == '4') {
            while (resposta_relatorios != '0') {
                resposta_relatorios = tela_relatorios();
                if (resposta_relatorios == '1') {
                    tela_relatorio_clientes();
                }
                else if (resposta_relatorios == '2') {
                    tela_relatorio_vestimentas();
                }
                else if (resposta_relatorios == '3') {
                    tela_relatorio_locacoes();
                }
                else if (resposta_relatorios != '0') {
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