char tela_clientes(void);
void tela_cadastro_cliente(char cpf[12], char nome[50], char nasc[11], char tel[16], char email[50]);
void tela_info_cliente(char *cpf, char *nome, char *nascimento, char *telefone, char *email);
char tela_alterar_cliente(char *nome, char *nascimento, char *telefone, char *email);
char tela_remover_cliente(char *cpf, char *nome, char *nascimento, char *telefone, char *email);