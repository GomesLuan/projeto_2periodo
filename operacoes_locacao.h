typedef struct locacao Locacao;
void cadastrar_locacao(void);
void info_locacao(void);
void alterar_locacao(void);
void remover_locacao(void);
void receber_produto_alugado(void);
void devolver_produto_alugado(void);
void grava_locacao(Locacao *loc);
Locacao *busca_locacao(long id, int incluir_excluido);
void edita_locacao(Locacao *loc_lida);
void exclui_locacao(long id);