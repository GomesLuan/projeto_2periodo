typedef struct vestimenta Vestimenta;
void cadastrar_vestimenta(void);
void info_vestimenta(void);
void alterar_vestimenta(void);
void remover_vestimenta(void);
void grava_vestimenta(Vestimenta *vest);
Vestimenta *busca_vestimenta(char *id, int incluir_excluido);
void edita_vestimenta(Vestimenta *vest_lida);
void exclui_vestimenta(char *id);