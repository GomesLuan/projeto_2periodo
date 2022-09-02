#include <stdio.h>
#include "telas.c"

int main(void) {
    //Inicio do programa
    char resposta_principal;
    //char resposta_clientes;
    //char resposta_roupas;
    //char resposta_locacoes;
    //char resposta_relatorios;
    while (resposta_principal != '0') {
        resposta_principal = tela_principal();
        if (resposta_principal == '5') {
            tela_informacoes();
        }
        else if (resposta_principal == '6') {
            tela_orientacoes();
        }  
    }
    return 0;
}