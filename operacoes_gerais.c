#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

char *gera_codigo_barras() {
    char *codigo = (char*) malloc(14*sizeof(char));
    int *digitos = (int*) malloc(12*sizeof(int));
    int num, soma2, verif;
    int soma1 = 0;
    srand(time(0));
    for (int i=0; i<12; i++) {
        num = rand()%10;
        digitos[i] = num;
        codigo[i] = num + '0';
        if (i%2 == 0) {
            soma1 += num;
        }
        else {
            soma1 += 3*num;
        }
    }
    soma2 = (soma1/10 + 1)*10;
    verif = (soma2 - soma1)%10;
    codigo[12] = verif + '0';
    codigo[13] = '\0';
    free(digitos);
    return codigo;
}

int converte_str_para_int(char* string) {
    int num = 0;
    int tam = strlen(string);
    for (int i=tam-1; i>=0; i--) {
        num += pow(10, i)*(string[tam-i-1] - '0');
    }
    if (num%10 != (string[tam-1] - '0')) {
        //Para resolver bug que acontece na função pow() em alguns casos
        num += 1;
    }
    return num;
}