typedef struct locacao {
    long id_loc;
    char cpf[12];
    char id_vest[14];
    char tam_vest;
    char data_inicio[9];
    char data_fim[9];
} Locacao;
char tela_locacoes(void);
void tela_cadastro_locacao(Locacao *loc);
void tela_info_locacao(Locacao *loc);
char tela_alterar_locacao(Locacao *loc);
char tela_remover_locacao(Locacao *loc);
char tela_receber_produto(Locacao *loc);
char tela_devolver_produto(Locacao *loc);
void cad_cpf_locatario(char *cpf);
void cad_id_vest(char *id);
void cad_tam_vest(char *tam);
void cad_data_inicio(char *data);
void cad_data_fim(char *data_fim, char *data_inicio);