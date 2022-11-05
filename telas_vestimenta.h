typedef struct vestimenta Vestimenta;
char tela_vestimentas(void);
void tela_cadastro_vestimenta(Vestimenta *vest);
void tela_info_vestimenta(Vestimenta *vest);
char tela_alterar_vestimenta(Vestimenta *vest);
char tela_remover_vestimenta(Vestimenta *vest);
void cad_nome_vest(char *nome);
void cad_num_vest(int *num, char tam);
void cad_preco_vest(float *preco);