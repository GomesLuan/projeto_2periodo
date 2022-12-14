typedef struct cliente Cliente;
typedef struct vestimenta Vestimenta;
typedef struct locacao Locacao;
char tela_relatorios(void);
void tela_relatorio_clientes(char ordem);
void tela_relatorio_vestimentas(void);
void tela_relatorio_locacoes(char status);
void exibe_cliente(Cliente *cl);
void exibe_vestimenta(Vestimenta *vest);
void exibe_locacao(Locacao *loc, Cliente *cl, Vestimenta *vest);
Cliente *ordena_cliente(void);
Cliente *posiciona_cliente(Cliente *lista, Cliente *novo_cl);