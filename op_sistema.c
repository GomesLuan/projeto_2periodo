#include <stdio.h>

#ifdef WIN32
#define SISTEMA 1
#else
#define SISTEMA 0
#endif

void limpar_tela(void) {
    if (SISTEMA == 1) {
        system("cls");
    }
    else {
        system("clear");
    }
}

void pausar_sistema(void) {
    if (SISTEMA == 1) {
        system("pause");
    }
    else {
        system("read -p \"Pressione ENTER para continuar \" saindo");
    }
}