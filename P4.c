/* P4.c */
/* Gustavo Alves Pacheco */
/* 11821ECP011 */

#include <stdio.h>

unsigned long long int ackermann(int m, int n);

int main(int argc, char const *argv[]) {
  int m, n;

  printf("Digite o valor de m: \n");
  scanf("%d", &m);
  printf("Digite o valor de n: \n");
  scanf("%d", &n);
  printf("O resultado foi: %llu", ackermann(m, n));

  return 0;
}

unsigned long long int ackermann(int m, int n) {
  if      (m == 0)           {return n + 1;}
  else if (m >  0 && n == 0) {return ackermann(m - 1, 1);}
  else if (m >  0 && n  > 0) {return ackermann(m - 1, ackermann(m, n - 1));}
}
