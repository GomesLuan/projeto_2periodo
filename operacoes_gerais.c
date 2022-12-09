#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "validacoes.h"
#include "operacoes_gerais.h"

void gera_codigo_barras(char *codigo) {
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
}

int converte_str_para_int(char* string) {
    int num = 0;
    int tam = strlen(string);
    for (int i=tam-1; i>=0; i--) {
        num += pow(10, i)*(string[tam-i-1] - '0');
    }
    while (num%10 != (string[tam-1] - '0')) {
        //Para resolver um bug que acontece na função pow() em alguns casos
        num += 1;
    }
    return num;
}

float converte_str_para_float(char* string) {
    float num = 0;
    int tam_int = 0;
    int ponto = 0;
    int i = 0;
    do {
        if (string[i] == '.' || string[i] == ',') {
            ponto = 1;
        }
        else if (ponto == 0) {
            tam_int += 1;
        }
        else {
            num += pow(10, tam_int-i)*(string[i] - '0');
        }
        i++;
    }
    while (string[i] != '\0');
    for (int j=tam_int-1; j>=0; j--) {
        num += pow(10, j)*(string[tam_int-j-1] - '0');
    }
    return num;
}

///////////
//Função adaptada de Smichak, disponível em https://stackoverflow.com/questions/10917491/building-a-date-string-in-c
///////////
void gera_data_hoje(char *data) {
    char *tempo = (char*) malloc(20*sizeof(char));
    time_t agora = time(NULL);
    struct tm *t = localtime(&agora);
    strftime(tempo, sizeof(tempo)-1, "%d %m %Y %H:%M", t);
    data[0] = tempo[0];
    data[1] = tempo[1];
    data[2] = tempo[3];
    data[3] = tempo[4];
    data[4] = tempo[6];
    data[5] = tempo[7];
    data[6] = tempo[8];
    data[7] = tempo[9];
    free(tempo);
}

void ordena_datas(char *data1, char *data2) {
    int desordenado = verifica_data_maior(data1, data2, 0);
    if (desordenado) {
        char *temp = (char*) malloc(9*sizeof(char));
        strcpy(temp, data1);
        strcpy(data1, data2);
        strcpy(data2, temp);
        free(temp);
    }
}

void altera_formato_data(char *data1, char *data2, int *dia1, int *mes1, int *ano1, int *dia2, int *mes2, int *ano2) {
    int *nums1 = (int*) malloc(8*sizeof(int));
    int *nums2 = (int*) malloc(8*sizeof(int));
    for (int i=0; i<8; i++) {
        nums1[i] = data1[i] - '0';
        nums2[i] = data2[i] - '0';
    }
    *dia1 = 10*nums1[0] + nums1[1];
    *mes1 = 10*nums1[2] + nums1[3];
    *ano1 = 1000*nums1[4] + 100*nums1[5] + 10*nums1[6] + nums1[7];
    *dia2 = 10*nums2[0] + nums2[1];
    *mes2 = 10*nums2[2] + nums2[3];
    *ano2 = 1000*nums2[4] + 100*nums2[5] + 10*nums2[6] + nums2[7];   
    free(nums1);
    free(nums2);
}

int diferenca_datas(char *data1, char *data2) {
    int num_dias[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dif = 0; 
    int dia1, mes1, ano1, dia2, mes2, ano2;
    ordena_datas(data1, data2);
    altera_formato_data(data1, data2, &dia1, &mes1, &ano1, &dia2, &mes2, &ano2);
    if (ano1 == ano2) {
        if (mes1 == mes2) {
            dif = dia2 - dia1;
            return dif;
        }
        else {
            dif += num_dias[mes1-1] - dia1 + dia2;
            for (int i=mes1; i<mes2-1; i++) {
                dif += num_dias[i];
            }
            if (bissexto(ano1) && ((mes1 == 2 || mes2 == 2) || (mes1 < 2 && mes2 > 2))) {
                dif += 1;
            }
        }
    }
    else {
        dif += num_dias[mes1-1] - dia1;
        for (int i=mes1; i<12; i++) {
            dif += num_dias[i];
        }
        if (bissexto(ano1) && mes1 <= 2) {
                dif += 1;
        }
        dif += dia2;
        for (int i=0; i<mes2-1; i++) {
            dif += num_dias[i];
        }
        if (bissexto(ano2) && mes2 > 2) {
                dif += 1;
        }
        for (int i=ano1+1; i<ano2; i++) {
            dif += 365;
            if (bissexto(i)) {
                dif += 1;
            }
        }
    }
    return dif;
}