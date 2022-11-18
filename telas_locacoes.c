#include <stdio.h>
#include <stdlib.h>
#include "validacoes.h"
#include "telas_locacoes.h"
#include "operacoes_cliente.h"
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

char tela_locacoes(void) {
    system("clear||cls");
    char resposta;
    printf("###################################################\n");
    printf("#           M E N U   D E   L O C A Ç Õ E S       #\n");
    printf("###################################################\n");
    printf("#       1 - Agendar locação                       #\n");
    printf("#       2 - Informações de locação                #\n");
    printf("#       3 - Alterar dados da locação              #\n");
    printf("#       4 - Cancelar agendamento                  #\n");
    printf("#       5 - Receber produto alugado               #\n");
    printf("#       6 - Devolver produto alugado              #\n");
    printf("#       0 - Retornar ao menu principal            #\n");
    printf("###################################################\n\n");
    printf("Escolha sua opção: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

void tela_cadastro_locacao(Locacao *loc) {
    system("clear||cls");
    printf("###########################################################\n");
    printf("#       A G E N D A M E N T O   D E   L O C A Ç Ã O       #\n");
    printf("###########################################################\n");
    printf("# Por favor, informe os dados solicitados:\n");
    cad_cpf_locatario(loc->cpf);
    cad_id_vest(loc->id_vest);
    cad_tam_vest(&loc->tam_vest, loc->id_vest);
    cad_data_inicio(loc->data_inicio);
    cad_data_fim(loc->data_fim, loc->data_inicio);
    printf("########################################################\n");
}

void tela_info_locacao(Locacao *loc) {
    system("clear||cls");
    printf("#################################################################\n");
    printf("#       I N F O R M A Ç Õ E S   D E   L O C A Ç Ã O             #\n");
    printf("#################################################################\n");
    printf("#       Numero de identificação: %ld\n", loc->id_loc);
    printf("#       CPF do cliente responsável: %s\n", loc->cpf);
    printf("#       Código do produto alugado: %s\n", loc->id_vest);
    printf("#       Tamanho da vestimenta: %c\n", loc->tam_vest);
    printf("#       Data de início: %s\n", loc->data_inicio);
    printf("#       Data de fim: %s\n", loc->data_fim);
    printf("#################################################################\n\n");
    printf("Pressione ENTER para continuar ");
    getchar();
}

char tela_alterar_locacao(Locacao *loc) {
    system("clear||cls");
    char resposta;
    printf("##############################################################\n");
    printf("#       A L T E R A R   D A D O S   D E   L O C A ÇÃ O       #\n");
    printf("##############################################################\n");
    printf("#       Qual informação gostaria de alterar?\n");
    printf("#       1 - CPF do cliente responsável: (%s)\n", loc->cpf);
    printf("#       2 - Código do produto alugado: (%s)\n", loc->id_vest);
    printf("#       3 - Tamanho da vestimenta alugada: (%c)\n", loc->tam_vest);
    printf("#       4 - Data de início da locação: (%s)\n", loc->data_inicio);
    printf("#       5 - Data de fim da locação: (%s)\n", loc->data_fim);
    printf("#       0 - Retornar ao menu de locação\n");
    printf("#########################################################\n\n");
    printf("Escolha sua opção: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

char tela_remover_locacao(Locacao *loc) {
    system("clear||cls");
    char resposta;
    printf("#########################################################################\n");
    printf("#             C A N C E L A M E N T O   D E   L O C A Ç Ã O             #\n");
    printf("#########################################################################\n");
    printf("#       Número de idenficação da locação: %ld\n", loc->id_loc);
    printf("#       CPF do cliente responsável: %s\n", loc->cpf);
    printf("#       Código do produto alugado: %s\n", loc->id_vest);
    printf("#       Tamanho da vestimenta alugada: %c\n", loc->tam_vest);
    printf("#       Data de início da locação: %s\n", loc->data_inicio);
    printf("#       Data de fim da locação: %s\n", loc->data_fim);
    printf("#\n");
    printf("#       Tem certeza que deseja cancelar este agendamento?\n");
    printf("#       1 - Sim\n");
    printf("#       2 - Não \n");
    printf("#########################################################################\n\n");
    printf("Escolha sua opção: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

char tela_receber_produto(Locacao *loc) {
    system("clear||cls");
    char resposta;
    printf("#######################################################################\n");
    printf("#             R E C E B I M E N T O   D E   P R O D U T O             #\n");
    printf("#######################################################################\n");
    printf("#       Número de idenficação da locação: %ld\n", loc->id_loc);
    printf("#       CPF do cliente responsável: %s\n", loc->cpf);
    printf("#       Código do produto alugado: %s\n", loc->id_vest);
    printf("#       Tamanho da vestimenta alugada: %c\n", loc->tam_vest);
    printf("#       Data de início da locação: %s\n", loc->data_inicio);
    printf("#       Data de fim da locação: %s\n", loc->data_fim);
    printf("#\n");
    printf("#       Deseja confirmar o recebimento do produto desta locação?\n");
    printf("#       1 - Sim\n");
    printf("#       2 - Não \n");
    printf("#######################################################################\n\n");
    printf("Escolha sua opção: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

char tela_devolver_produto(Locacao *loc) {
    system("clear||cls");
    char resposta;
    printf("####################################################################\n");
    printf("#             D E V O L U Ç Ã O   D E   P R O D U T O              #\n");
    printf("####################################################################\n");
    printf("#       Número de idenficação da locação: %ld\n", loc->id_loc);
    printf("#       CPF do cliente responsável: %s\n", loc->cpf);
    printf("#       Código do produto alugado: %s\n", loc->id_vest);
    printf("#       Tamanho da vestimenta alugada: %c\n", loc->tam_vest);
    printf("#       Data de início da locação: %s\n", loc->data_inicio);
    printf("#       Data de fim da locação: %s\n", loc->data_fim);
    printf("#\n");
    printf("#       Deseja confirmar a devolução do produto desta locação?\n");
    printf("#       1 - Sim\n");
    printf("#       2 - Não \n");
    printf("####################################################################\n\n");
    printf("Escolha sua opção: ");
    scanf("%c", &resposta);
    getchar();
    return resposta;
}

void cad_cpf_locatario(char *cpf) {
    int cpf_valido = 0;
    int cpf_cadastrado = 0;
    do {
        printf("# CPF do locatário (apenas números): ");
        scanf("%s", cpf);
        getchar();
        cpf_valido = valida_cpf(cpf);
        if (cpf_valido) {
            Cliente *cl = busca_cliente(cpf, 0);
            if (cl != NULL) {
                cpf_cadastrado = 1;
            }
            free(cl);
        }
        if (!cpf_valido || !cpf_cadastrado) {
            if (!cpf_valido) {
                printf("# Valor inválido! ");
            }
            else {
                printf("# Este CPF não está cadastrado.");
            }
            getchar();
            printf("\x1b[2K");
            printf("\x1b[1F");
            printf("\x1b[2K");
            printf("\x1b[1F");
            printf("\x1b[2K");
        }
    } while (!cpf_valido || !cpf_cadastrado);
}

void cad_id_vest(char *id) {
    int id_cadastrado = 0;
    do {
        printf("# Código de identificação da vestimenta: ");
        scanf("%s", id);
        getchar();
        Vestimenta *vest = busca_vestimenta(id, 0);
        if (vest != NULL) {
            id_cadastrado = 1;
        }
        free(vest);
        if (!id_cadastrado) {
            printf("# Não há nenhuma vestimenta cadastrada com este código.");
            getchar();
            printf("\x1b[2K");
            printf("\x1b[1F");
            printf("\x1b[2K");
            printf("\x1b[1F");
            printf("\x1b[2K");
        }
    } while (!id_cadastrado);
}

void cad_tam_vest(char *tam, char* id_vest) {
    int disponivel = 0;
    int tam_valido = 0;
    do {
        printf("# Tamanho da vestimenta (P/M/G): ");
        scanf("%c", tam);
        getchar();
        tam_valido = valida_tamanho_vest(*tam);
        if (tam_valido) {
            disponivel = disponibilidade_vest(id_vest, *tam);
        }
        if (!tam_valido || !disponivel) {
            if (!tam_valido) {
                printf("Valor inválido! ");
            }
            else {
                printf("Não há vestimentas desse tamanho disponíveis ");
            }
            getchar();
            printf("\x1b[2K");
            printf("\x1b[1F");
            printf("\x1b[2K");
            printf("\x1b[1F");
            printf("\x1b[2K");
        }
    } while (!tam_valido || !disponivel);
}

void cad_data_inicio(char *data) {
    int data_valida = 0;
    do {
        printf("# Data de início da locação (ddmmaaaa): ");
        scanf("%s", data);
        getchar();
        data_valida = valida_data(data);
        if (!data_valida) {
            printf("Valor inválido! ");
            getchar();
            printf("\x1b[2K");
            printf("\x1b[1F");
            printf("\x1b[2K");
            printf("\x1b[1F");
            printf("\x1b[2K");
        }
    } while (!data_valida);
}

void cad_data_fim(char *data_fim, char *data_inicio) {
    int data_valida;
    int data_maior;
    do {
        data_valida = 0;
        data_maior = 0;
        printf("# Data de fim da locação (ddmmaaaa): ");
        scanf("%s", data_fim);
        getchar();
        data_valida = valida_data(data_fim);
        if (data_valida) {
            data_maior = verifica_data_maior(data_fim, data_inicio);
        }
        if (!data_valida || !data_maior) {
            printf("Valor inválido! ");
            getchar();
            printf("\x1b[2K");
            printf("\x1b[1F");
            printf("\x1b[2K");
            printf("\x1b[1F");
            printf("\x1b[2K");
        }
    } while (!data_valida || !data_maior);
}