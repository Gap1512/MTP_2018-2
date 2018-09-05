/* P1.c */
/* Gustavo Alves Pacheco */
/* 11821ECP011 */

#include <stdio.h>

int data_input (char *bit);
int data_output (char *bit, int state);
int data_processing (char *bit, int *state_pointer);

int main() {
  //Declaracao de Variaveis
  int  error, state = 0, *state_pointer;
  char bit[256];
  state_pointer = &state;
  //Inserir Dados
  error = data_input(bit);
  if (error) {printf("Erro ao importar os dados\n"); return 1;}
  //Processamento de Dados
  error = data_processing(bit, state_pointer);
  if (error) {printf("Erro ao processar os dados\n"); return 1;}
  //Exibir Dados
  error = data_output(bit, state);
  if (error) {printf("Erro ao exibir os dados\n"); return 1;}
  //Retorno da Funcao Main
  return 0;
}

int data_input(char *bit) {
  printf("Insira a sequencia de bits a ser testada:\n");
  scanf("%s", bit);
  return 0;
}

int data_output(char *bit, int state) {
  if (!state) printf("'%s' e multiplo de 3\n", bit);
  else printf("'%s' nao e\n");
  return 0;
}

int data_processing (char *bit, int *state_pointer) {
  int i = 0;
  while (bit[i] != '\0') {
    if(*state_pointer == 0 && bit[i] == '0') {*state_pointer = 0;}
    else if(*state_pointer == 0 && bit[i] == '1') {*state_pointer = 1;}
    else if(*state_pointer == 1 && bit[i] == '0') {*state_pointer = 2;}
    else if(*state_pointer == 1 && bit[i] == '1') {*state_pointer = 0;}
    else if(*state_pointer == 2 && bit[i] == '0') {*state_pointer = 1;}
    else if(*state_pointer == 2 && bit[i] == '1') {*state_pointer = 2;}
    else return 1;
    i += 1;
  }
  return 0;
}
