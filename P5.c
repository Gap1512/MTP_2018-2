/* P5.c */
/* Gustavo Alves Pacheco */
/* 11821ECP011 */

#include <stdio.h>

typedef
  unsigned long long int
Bytes8;

typedef struct {
  Bytes8 a, c, m, rand_max, atual;
} LCG;

void semente(LCG *r, Bytes8 seed);
Bytes8 lcg_rand(LCG *r);
double lcg_rand_01(LCG *r);
void gera_numeros(float *vetor, int tam, float min, float max, LCG *r);
float soma(float *inicio_vetor, float *fim_vetor);
float soma_aux(float *inicio_vetor, float *fim_vetor, float resultado);
float produto(float *inicio_vetor, float *fim_vetor);
float produto_aux(float *inicio_vetor, float *fim_vetor, float resultado);
void operacao(float *inicio_vetor, float *fim_vetor);

int main(int argc, char const *argv[]) {
  LCG random;
  float vetor[50];
  semente(&random, 123456);
  gera_numeros(vetor, 50, 0.5, 1.5, &random);
  operacao(vetor, &vetor[49]);
  return 0;
}

void semente(LCG *r, Bytes8 seed) {
  r->a = 0x5DEECE66DULL;
  r->c = 11ULL;
  r->m = (1ULL << 48);
  r->rand_max = r->m - 1;
  r->atual = seed;
}

Bytes8 lcg_rand(LCG *r) {
  r->atual = (r->a * r->atual + r->c) % r->m;
  return r->atual;
}

double lcg_rand_01(LCG *r) {
  return ((double) lcg_rand(r))/(r->rand_max);
}

void gera_numeros(float *vetor, int tam, float min, float max, LCG *r) {
  int i;
  printf("Sera Gerado Um Vetor Com 50 Elementos\n");
  for(i = 0; i < tam; i++) {
    vetor[i] = (max - min) * lcg_rand_01(r) + min;
    printf("%f\n", vetor[i]);
  }
}

float soma(float *inicio_vetor, float *fim_vetor) {
  return soma_aux(inicio_vetor, fim_vetor, 0);
}

float produto(float *inicio_vetor, float *fim_vetor) {
  return produto_aux(inicio_vetor, fim_vetor, 1);
}

float soma_aux(float *inicio_vetor, float *fim_vetor, float resultado) {
return (inicio_vetor == fim_vetor) ?
  resultado + *inicio_vetor : soma_aux(inicio_vetor + 1, fim_vetor, (resultado + *inicio_vetor));
}

float produto_aux(float *inicio_vetor, float *fim_vetor, float resultado) {
return (inicio_vetor == fim_vetor) ?
  resultado * *inicio_vetor : produto_aux(inicio_vetor + 1, fim_vetor, (resultado * *inicio_vetor));
}

void operacao(float *inicio_vetor, float *fim_vetor) {
  int escolha;
  float resultado = 0;
  printf("Deseja Realizar Qual Operacao? [1 - Somatorio/2 - Produtorio]: ");
  scanf("%d", &escolha);
  getchar();
  if      (escolha == 1) {resultado = soma(inicio_vetor, fim_vetor); printf("%f", resultado);}
  else if (escolha == 2) {resultado = produto(inicio_vetor, fim_vetor); printf("%f", resultado);}
  else                   {printf("Opcao Invalida");}
}
