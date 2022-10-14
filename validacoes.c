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
