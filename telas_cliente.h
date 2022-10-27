typedef struct cliente {
    char cpf[12];
    char nome[81];
    char nasc[9];
    char tel[14];
    char email[81];
} Cliente;
char tela_clientes(void);
void tela_cadastro_cliente(Cliente *cl);
void tela_info_cliente(Cliente *cl);
char tela_alterar_cliente(Cliente *cl);
char tela_remover_cliente(Cliente *cl);
void cad_cpf_cliente(char *cpf);
void cad_nome_cliente(char *nome);
void cad_nasc_cliente(char *nasc);
void cad_tel_cliente(char *tel);
void cad_email_cliente(char *email);