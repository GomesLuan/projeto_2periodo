char tela_locacoes(void);
void tela_cadastro_locacao(char **num_id, char **cpf, char **nome_vest, char *tam_vest, char **data_inicio, char **data_fim);
void tela_info_locacao(char *num_id, char *cpf, char *nome_vest, char *tam_vest, char *data_inicio, char *data_fim);
char tela_alterar_locacao(char *cpf, char *nome_vest, char *tam_vest, char *data_inicio, char *data_fim);
char tela_remover_locacao(char *num_id, char *cpf, char *nome_vest, char *tam_vest, char *data_inicio, char *data_fim);