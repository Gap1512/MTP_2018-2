#include <stdio.h>
#include <setjmp.h>

int a_exp_b(int a, int b){
  int acc = 1, count;
  for (count = 0; count < b; count++, acc = acc * a);
  return acc;
}

int input(char *source){
  printf("Digite A String A Ser Analisada:\n");
  scanf("%s", source);
  return 0;
}

int output(int *number){
  printf("%d", *number);
  return 0;
}

int string_to_number(char *source, int *number){
  int destiny[256], dsti = 0, scri = 0, i;

  for(scri; source[scri] != '\0'; scri++) {
    if ((source[scri] >=48) && (source[scri] <= 57)){
      destiny[dsti] = source[scri] - 48;
      dsti++;
    }
  }
  destiny[dsti] = '\0';

  for(i = 0; destiny[i] != '\0'; i++){
    dsti--;
    *number = *number + a_exp_b(10, dsti) * destiny[i];
  }

  return 0;
}

int main(int argc, char const *argv[]) {
  char source[256];
  int number = 0, jmp;
  jmp_buf env_buffer;

  jmp = setjmp(env_buffer);

  if (jmp != 0) {printf("Error %d Occurred\n", jmp);}

  if (input(source)) longjmp(env_buffer, 1);

  if (string_to_number(source, &number)) longjmp(env_buffer, 2);

  if (output(&number)) longjmp(env_buffer, 3);

  return 0;
}
