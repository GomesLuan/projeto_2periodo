char tela_clientes(void);
void tela_cadastro_cliente(char **cpf, char **nome, char **nasc, char **tel, char **email);
void tela_info_cliente(char *cpf, char *nome, char *nascimento, char *telefone, char *email);
char tela_alterar_cliente(char *nome, char *nascimento, char *telefone, char *email);
char tela_remover_cliente(char *cpf, char *nome, char *nascimento, char *telefone, char *email);