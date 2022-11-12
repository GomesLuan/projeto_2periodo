#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operacoes_cliente.h"
#include "operacoes_locacao.h"
#include "operacoes_vestimenta.h"

typedef struct cliente {
    char cpf[12];
    char nome[81];
    char nasc[9];
    char tel[14];
    char email[81];
    char status;
} Cliente;

typedef struct vestimenta {
    char id[14];
    char nome[81];
    int num_p;
    int num_m;
    int num_g;
    float preco;
    char status;
} Vestimenta; 

typedef struct locacao {
    long id_loc;
    char cpf[12];
    char id_vest[14];
    char tam_vest;
    char data_inicio[9];
    char data_fim[9];
    char status;
} Locacao;

int valida_cpf(char cpf[12]) {
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

int valida_nome_pessoa(char nome[81]) {
    int i = 0;
    while (nome[i] != '\0') {
        if ((nome[i] >= '0' && nome[i] <= '9') || (nome[i] == '.') || (nome[i] == '-') || (nome[i] == ',') 
        || (nome[i] == '_') || (nome[i] == '#')) {
            return 0;
        }
        if ((nome[i] == ' ') && (i != 0)) {
            if (nome[i-1] == ' ') {
                return 0;
            }
        }
        i++;
    }
    if (i == 0) {
        return 0;
    }
    return 1;
}

int valida_data(char data[9]) {
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

int valida_telefone(char tel[14]) {
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
int valida_email(char email[81]) {
    int arroba = 0;
    int ponto = 0;
    int tam = strlen(email);
    if (email[0] < 'a' || email[0] > 'z') {
        return 0;
    }
    for (int i=0; i<tam; i++) {
        if ((email[i] < 'a' || email[i] > 'z') && (email[i] < '0' || email[i] > '9') && email[i] != '.' 
        && email[i] != '-' && email[i] != '_' && email[i] != '@') {
            return 0;
        }
        if (email[i] == '@'){
            arroba = 1;
        }
        if (arroba) {
            if (email[i] == '-' || email[i] == '_') {
                return 0;
            }
            else if(email[i] == '.'){
                ponto = 1;
            }
        }
        if (arroba && ponto) {
            if (email[i] >= 'a' && email[i] <= 'z') {
                return 1;
            }
        }  
    }
    return 0;
}  

int valida_nome_vest(char *nome) {
    int i = 0;
    while (nome[i] != '\0') {
        if ((nome[i] == ',') || (nome[i] == '_') || (nome[i] == '#')) {
            return 0;
        }
        if ((nome[i] == ' ') && (i != 0)) {
            if (nome[i-1] == ' ') {
                return 0;
            }
        }
        i++;
    }
    if (i == 0) {
        return 0;
    }
    return 1;
}

int valida_inteiro(char *num) {
    int i = 0;
    while (num[i] != '\0') {
        if (num[i] < '0' || num[i] > '9') {
            return 0;
        }
        i++;
    }
    if (i == 0) {
        return 0;
    }
    return 1;
}

int valida_float(char *din) {
    int i = 0;
    int virgula = 0;
    while (din[i] != '\0') {
        if ((din[i] < '0' || din[i] > '9') && din[i] != '.' && din[i] != ',') {
            return 0;
        }
        if (din[i] == '.' || din[i] == ',') {
            if (virgula == 1) {
                return 0;
            }
            virgula = 1;
        }
        i++;
    }
    if (i == 0) {
        return 0;
    }
    return 1;
}

int valida_tamanho_vest(char tam) {
    if (tam != 'P' && tam != 'M' && tam != 'G' && tam != 'p' && tam != 'm' && tam != 'g') {
        return 0;
    }
    return 1;
}

///////////
//Função adaptada de Vinicius Maia com base no algoritmo do professor Flavius Gorgonio
//////////
int verifica_data_maior(char *data1, char *data2) {
    int *nums1 = (int*) malloc(8*sizeof(int));
    int *nums2 = (int*) malloc(8*sizeof(int));
    for (int i=0; i<8; i++) {
        nums1[i] = data1[i] - '0';
        nums2[i] = data2[i] - '0';
    }
    int dia1 = 10*nums1[0] + nums1[1];
    int mes1 = 10*nums1[2] + nums1[3];
    int ano1 = 1000*nums1[4] + 100*nums1[5] + 10*nums1[6] + nums1[7];
    int dia2 = 10*nums2[0] + nums2[1];
    int mes2 = 10*nums2[2] + nums2[3];
    int ano2 = 1000*nums2[4] + 100*nums2[5] + 10*nums2[6] + nums2[7];   
    if (ano1 < ano2) {
        return 0;
    }
    else if (ano1 > ano2){
        return 1;
    }
    else {
        if (mes1 < mes2) {
            return 0;
        }
        else if (mes1 > mes2) {
            return 1;
        }
        else {
            if (dia1 <= dia2) {
                return 0;
            }
            return 1;
        }
    }
}

int verifica_exist_cliente(char *cpf) {
    Cliente *cl = busca_cliente(cpf, 1);
    if (cl == NULL) {
        free(cl);
        return 0;
    }
    free(cl);
    return 1;
}

int verifica_exist_vest(char *id) {
    Vestimenta *vest = busca_vestimenta(id, 1);
    if (vest == NULL) {
        free(vest);
        return 0;
    }
    free(vest);
    return 1;
}

int verifica_exist_loc(long id) {
    Locacao *loc = busca_locacao(id);
    if (loc == NULL) {
        free(loc);
        return 0;
    }
    free(loc);
    return 1;
}