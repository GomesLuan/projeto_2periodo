#include <stdio.h>
#include "telas.c"

int main(void) {
    //Inicio do programa
    char resposta_principal = '1';
    char resposta_clientes = '1';
    //char resposta_roupas;
    //char resposta_locacoes;
    //char resposta_relatorios;
    while (resposta_principal != '0') {
        resposta_principal = tela_principal();
        if (resposta_principal == '1') {
            while (resposta_clientes != '0') {
                resposta_clientes = tela_clientes();
            }
        }
        if (resposta_principal == '5') {
            tela_informacoes();
        }
        else if (resposta_principal == '6') {
            tela_orientacoes();
        }  
    }
    return 0;
}