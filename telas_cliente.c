#include <stdio.h>
#include <stdlib.h>
#include "validacoes.h"
#include "telas_cliente.h"
#include "operacoes_cliente.h"

char tela_clientes(void) {
    system("clear||cls");
    char resposta;
    printf("#########################################\n");
    printf("#    M E N U   D E   C L I E N T E S    #\n");
    printf("#########################################\n");
    printf("#       1 - Cadastrar cliente           #\n");
    printf("#       2 - Informações de cliente      #\n");
    printf("#       3 - Alterar dados de cliente    #\n");
    printf("#       4 - Remover cliente             #\n");
    printf("#       0 - Retornar ao menu principal  #\n");
    printf("#########################################\n\n");
    printf("Escolha sua opção: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

void tela_cadastro_cliente(Cliente *cl) {
    system("clear||cls");
    printf("####################################################\n");
    printf("#     C A D A S T R O   D E   C L I E N T E S      #\n");
    printf("####################################################\n");
    printf("# Por favor, informe os dados solicitados:\n");
    cad_cpf_cliente(cl->cpf);
    cad_nome_cliente(cl->nome);
    cad_nasc_cliente(cl->nasc);
    cad_tel_cliente(cl->nome);
    cad_email_cliente(cl->email);
    printf("####################################################\n");
}

void tela_info_cliente(Cliente *cl) {
    system("clear||cls");
    printf("###########################################################\n");
    printf("#       I N F O R M A Ç Õ E S   D E   C L I E N T E       #\n");
    printf("###########################################################\n");
    printf("#       CPF: %s\n", cl->cpf);
    printf("#       Nome: %s\n", cl->nome);
    printf("#       Data de nascimento: %s\n", cl->nasc);
    printf("#       Telefone: %s\n", cl->tel);
    printf("#       E-Mail: %s\n", cl->email);
    printf("###########################################################\n\n");
    printf("Pressione ENTER para continuar ");
    getchar();
}

char tela_alterar_cliente(Cliente *cl) {
    system("clear||cls");
    char resposta;
    printf("#########################################################\n");
    printf("#    A L T E R A R   D A D O S   D E   C L I E N T E    #\n");
    printf("#########################################################\n");
    printf("#       Qual informação gostaria de alterar?\n");
    printf("#       1 - Nome (%s)\n", cl->nome);
    printf("#       2 - Data de nascimento (%s)\n", cl->nasc);
    printf("#       3 - Telefone (%s)\n", cl->tel);
    printf("#       4 - E-mail (%s)\n", cl->email);
    printf("#       0 - Retornar ao menu de clientes\n");
    printf("#########################################################\n\n");
    printf("Escolha sua opção: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

char tela_remover_cliente(Cliente *cl) {
    system("clear||cls");
    char resposta;
    printf("#############################################################\n");
    printf("#            R E M O Ç Ã O   D E   C L I E N T E            #\n");
    printf("#############################################################\n");
    printf("#       CPF: %s\n", cl->cpf);
    printf("#       Nome: %s\n", cl->nome);
    printf("#       Data de nascimento: %s\n", cl->nasc);
    printf("#       Telefone: %s\n", cl->tel);
    printf("#       E-Mail: %s\n", cl->email);
    printf("#\n");
    printf("#       Tem certeza que deseja remover este cliente?\n");
    printf("#       1 - Sim\n");
    printf("#       2 - Não \n");
    printf("#############################################################\n\n");
    printf("Escolha sua opção: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

void cad_cpf_cliente(char cpf[12]) {
    int cpf_valido = 0;
    do {
    printf("# CPF (apenas números): ");
    scanf("%s", cpf);
    getchar();
    cpf_valido = valida_cpf(cpf);
    if (!cpf_valido) {
        printf("Valor inválido! ");
        getchar();
        printf("\x1b[2K");
        printf("\x1b[1F");
        printf("\x1b[2K");
        printf("\x1b[1F");
        printf("\x1b[2K");
    }
    } while (!cpf_valido);
}

void cad_nome_cliente(char nome[81]) {
    int nome_valido = 0;
    do {
    printf("# Nome: ");
    scanf("%[A-Z a-z 0-9 .,-_# áéíóúâôãõç ÁÉÍÓÚÂÔÃÕÇ]", nome);
    getchar();
    nome_valido = valida_nome_pessoa(nome);
    if (!nome_valido) {
        printf("Valor inválido! ");
        getchar();
        printf("\x1b[2K");
        printf("\x1b[1F");
        printf("\x1b[2K");
        printf("\x1b[1F");
        printf("\x1b[2K");
    }
    } while (!nome_valido);
}

void cad_nasc_cliente(char nasc[9]) {
    int nasc_valido = 0;
    do {
    printf("# Data de nascimento (ddmmaaaa): ");
    scanf("%s", nasc);
    getchar();
    nasc_valido = valida_data(nasc);
    if (!nasc_valido) {
        printf("Valor inválido! ");
        getchar();
        printf("\x1b[2K");
        printf("\x1b[1F");
        printf("\x1b[2K");
        printf("\x1b[1F");
        printf("\x1b[2K");
    }
    } while (!nasc_valido);
}

void cad_tel_cliente(char tel[14]) {
    int tel_valido = 0;
    do {
    printf("# Telefone para contato (apenas números): ");
    scanf("%s", tel);
    getchar();
    tel_valido = valida_telefone(tel);
    if (!tel_valido) {
        printf("Valor inválido! ");
        getchar();
        printf("\x1b[2K");
        printf("\x1b[1F");
        printf("\x1b[2K");
        printf("\x1b[1F");
        printf("\x1b[2K");
    }
    } while (!tel_valido);
}

void cad_email_cliente(char email[81]) {
    int email_valido = 0;
    do {
    printf("# E-mail para contato: ");
    scanf("%s", email);
    getchar();
    email_valido = valida_email(email);
    if (!email_valido) {
        printf("Valor inválido! ");
        getchar();
        printf("\x1b[2K");
        printf("\x1b[1F");
        printf("\x1b[2K");
        printf("\x1b[1F");
        printf("\x1b[2K");
    }
    } while (!email_valido);
}