#include <stdio.h>
#include <stdlib.h>

int valida_cpf(char *cpf) {
    int soma = 0;
    int d1 = 0;
    int d2 = 0;
    int *nums = (int*) malloc(11*sizeof(int));
    for (int i=0; i<11; i++) {
        if (cpf[i] < '0' || cpf[i] > '9') {
            free(nums);
            return 0;
        }
        nums[i] = cpf[i] - '0';
    }
    for (int i=0; i<9; i++) {
        soma += nums[i]*(10 - i);
    }
    d1 = 11 - (soma % 11);
    if (d1 == 10 || d1 == 11) {
        d1 = 0;
    }
    if (d1 != nums[9]) {
        free(nums);
        return 0;
    }
    soma = 0;
    for (int i=0; i<10; i++) {
        soma += nums[i]*(11 - i);
    }
    d2 = 11 - (soma % 11);
    if (d2 == 10 || d2 == 11) {
        d2 = 0;
    }
    if (d2 != nums[10]) {
        free(nums);
        return 0;
    }
    free(nums);
    return 1;
}

int valida_nome(char *nome) {
    int i = 0;
    while (nome[i] != '\0') {
        if ((nome[i] >= '0' && nome[i] <= '9') || (nome[i] == '.') || (nome[i] == '-') || (nome[i] == ',') || (nome[i] == '_') || (nome[i] == '#')) {
            return 0;
        }
        if ((nome[i] == ' ') && (i != 0)) {
            if (nome[i-1] == ' ') {
                return 0;
            }
        }
        i++;
    }
    return 1;
}

int valida_data(char *data) {
    int *nums = (int*) malloc(8*sizeof(int));
    for (int i=0; i<8; i++) {
        if (data[i] < '0' || data[i] > '9') {
            free(nums);
            return 0;
        }
        nums[i] = data[i] - '0';
    }
    int dia = 10*nums[0] + nums[1];
    int mes = 10*nums[2] + nums[3];
    int ano = 1000*nums[4] + 100*nums[5] + 10*nums[6] + nums[7];
    if (ano >= 0 && mes >= 1 && mes <= 12) {
        if ((mes==4 || mes==6 || mes==9 || mes==11) && (dia>=1 && dia<=30)) {
            free(nums);
            return 1;
        }
        else if ((mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) && (dia>=1 && dia<=31)) {
            free(nums);
            return 1;
        }
        else if (mes==2 && (dia>=1 && dia<=28)) {
            free(nums);
            return 1;
        }
        else if ((mes==2) && (dia==29) && (((ano%4 == 0) && (ano%100 != 0)) || (ano%400 == 0))) {
            free(nums);
            return 1;
        }
    }
    free(nums);
    return 0;
}

int valida_telefone(char *tel) {
    int i = 0;
    while (tel[i] != '\0') {
        if (tel[i] < '0' || tel[i] > '9') {
            return 0;
        }
        i++;
    }
    if (i < 8) {
        return 0;
    }
    return 1;
}
