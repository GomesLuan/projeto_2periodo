#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

void gera_codigo_barras(char *codigo) {
    int *digitos = (int*) malloc(12*sizeof(int));
    int num, soma2, verif;
    int soma1 = 0;
    srand(time(0));
    for (int i=0; i<12; i++) {
        num = rand()%10;
        digitos[i] = num;
        codigo[i] = num + '0';
        if (i%2 == 0) {
            soma1 += num;
        }
        else {
            soma1 += 3*num;
        }
    }
    soma2 = (soma1/10 + 1)*10;
    verif = (soma2 - soma1)%10;
    codigo[12] = verif + '0';
    codigo[13] = '\0';
    free(digitos);
}

int converte_str_para_int(char* string) {
    int num = 0;
    int tam = strlen(string);
    for (int i=tam-1; i>=0; i--) {
        num += pow(10, i)*(string[tam-i-1] - '0');
    }
    while (num%10 != (string[tam-1] - '0')) {
        //Para resolver um bug que acontece na função pow() em alguns casos
        num += 1;
    }
    return num;
}

float converte_str_para_float(char* string) {
    float num = 0;
    int tam_int = 0;
    int ponto = 0;
    int i = 0;
    do {
        if (string[i] == '.' || string[i] == ',') {
            ponto = 1;
        }
        else if (ponto == 0) {
            tam_int += 1;
        }
        else {
            num += pow(10, tam_int-i)*(string[i] - '0');
        }
        i++;
    }
    while (string[i] != '\0');
    for (int j=tam_int-1; j>=0; j--) {
        num += pow(10, j)*(string[tam_int-j-1] - '0');
    }
    return num;
}

///////////
//Função adaptada de Smichak, disponível em https://stackoverflow.com/questions/10917491/building-a-date-string-in-c
///////////
void gera_data_hoje(char *data) {
    char *tempo = (char*) malloc(20*sizeof(char));
    time_t agora = time(NULL);
    struct tm *t = localtime(&agora);
    strftime(tempo, sizeof(tempo)-1, "%d %m %Y %H:%M", t);
    data[0] = tempo[0];
    data[1] = tempo[1];
    data[2] = tempo[3];
    data[3] = tempo[4];
    data[4] = tempo[6];
    data[5] = tempo[7];
    data[6] = tempo[8];
    data[7] = tempo[9];
    free(tempo);
}

/*
int exclusao_fisica(){
  char name[] = "clientes.dat" && "vestimenta.dat" && "locacoes.dat";
  FILE *file = fopen(name, "r");

  if (file)
  {
    printf("Leitura de arquivo realizada\n");
    fclose(file);
    printf("\nVoltando...: %d\n", remove(file));
  }
  else{
    printf("Arquivo não encontrado\n");
    printf("\nVoltando...: %d\n", remove(file));
  }
  
  return 0;   
}
*/