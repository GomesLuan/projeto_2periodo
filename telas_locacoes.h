char tela_locacoes(void);
void tela_cadastro_locacao(char num_id[7], char cpf[12], char nome_vest[50], char tam_vest[2], char data_inicio[11], char data_fim[11]);
void tela_info_locacao(char *num_id, char *cpf, char *nome_vest, char *tam_vest, char *data_inicio, char *data_fim);
char tela_alterar_locacao(char *cpf, char *nome_vest, char *tam_vest, char *data_inicio, char *data_fim);
char tela_remover_locacao(char *num_id, char *cpf, char *nome_vest, char *tam_vest, char *data_inicio, char *data_fim);
char tela_receber_produto(char *num_id, char *cpf, char *nome_vest, char *tam_vest, char *data_inicio, char *data_fim);
char tela_devolver_produto(char *num_id, char *cpf, char *nome_vest, char *tam_vest, char *data_inicio, char *data_fim);