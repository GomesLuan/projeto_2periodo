typedef struct cliente Cliente;
void cadastrar_cliente(void);
void info_cliente(void);
void alterar_cliente(void);
void remover_cliente(void);
void grava_cliente(Cliente *cl);
Cliente *busca_cliente(char *cpf, int inclui_excluido);
void edita_cliente(Cliente *cl_lido);
void exclui_cliente(char *cpf);