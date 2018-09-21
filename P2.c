/* P2.c */
/* Gustavo Alves Pacheco */
/* 11821ECP011 */

#include <stdio.h>

int exptwo(int i) {
  int acc = 1, count;
  for (count = 0; count < i; count++, acc = acc * 2);
  return acc;
}

int expoct(int i) {
  int acc = 1, count;
  for (count = 0; count < i; count++, acc = acc * 8);
  return acc;
}

int tabela_conversora(int value, int i, char *bits) {
  switch (value) {
    case 0:
    bits[i] = '0';
    bits[i+1] = '0';
    bits[i+2] = '0';
    bits[i+3] = '0';
    break;
    case 1:
    bits[i] = '0';
    bits[i+1] = '0';
    bits[i+2] = '0';
    bits[i+3] = '1';
    break;
    case 2:
    bits[i] = '0';
    bits[i+1] = '0';
    bits[i+2] = '1';
    bits[i+3] = '0';
    break;
    case 3:
    bits[i] = '0';
    bits[i+1] = '0';
    bits[i+2] = '1';
    bits[i+3] = '1';
    break;
    case 4:
    bits[i] = '0';
    bits[i+1] = '1';
    bits[i+2] = '0';
    bits[i+3] = '0';
    break;
    case 5:
    bits[i] = '0';
    bits[i+1] = '1';
    bits[i+2] = '0';
    bits[i+3] = '1';
    break;
    case 6:
    bits[i] = '0';
    bits[i+1] = '1';
    bits[i+2] = '1';
    bits[i+3] = '0';
    break;
    case 7:
    bits[i] = '0';
    bits[i+1] = '1';
    bits[i+2] = '1';
    bits[i+3] = '1';
    break;
    case 8:
    bits[i] = '1';
    bits[i+1] = '0';
    bits[i+2] = '0';
    bits[i+3] = '0';
    break;
    case 9:
    bits[i] = '1';
    bits[i+1] = '0';
    bits[i+2] = '0';
    bits[i+3] = '1';
    break;
    case 10:
    bits[i] = '1';
    bits[i+1] = '0';
    bits[i+2] = '1';
    bits[i+3] = '0';
    break;
    case 11:
    bits[i] = '1';
    bits[i+1] = '0';
    bits[i+2] = '1';
    bits[i+3] = '1';
    break;
    case 12:
    bits[i] = '1';
    bits[i+1] = '1';
    bits[i+2] = '0';
    bits[i+3] = '0';
    break;
    case 13:
    bits[i] = '1';
    bits[i+1] = '1';
    bits[i+2] = '0';
    bits[i+3] = '1';
    break;
    case 14:
    bits[i] = '1';
    bits[i+1] = '1';
    bits[i+2] = '1';
    bits[i+3] = '0';
    break;
    case 15:
    bits[i] = '1';
    bits[i+1] = '1';
    bits[i+2] = '1';
    bits[i+3] = '1';
    break;
  }
  return 0;
}

int bin_to_dec(char *bits, int *dec_pointer) {
  int i = 0, j = 0, expaux = 0, sum = 0, bit_value = 0;
  while (bits[i] != '\0') {i++;}
  for(i = i - 1, j; bits[j] != '\0'; i--, j++) {
    if (bits[j] == '1') bit_value = 1; else bit_value = 0;
    expaux = exptwo(i);
    sum = sum + (bit_value * expaux);
  }
  *dec_pointer = sum;
  return 0;
}

int dec_to_hex(int *dec, char *hex){
  if (!*dec) hex[0] = '0';
  else {
    int counter = 0, ascii, mod = 0, aux = *dec;
    while (aux > 0) {
      aux = aux / 16;
      counter++;
    }
    hex[counter]='\0';
    while (*dec > 0) {
      counter--;
      ascii = 0;
      mod = (*dec % 16);
      if (mod < 10) ascii = 48; else ascii = 55;
      hex[counter] = mod + ascii;
      *dec = (*dec / 16);
    }
  }
  return 0;
}

int bin_to_hex(char *bits, char *hex) {
  int error, dec;
  error = bin_to_dec(bits, &dec);
  if (error) return 1;
  error = dec_to_hex(&dec, hex);
  if (error) return 1;
  return 0;
}

int hex_to_bin(char *hex, char *bits) {
  int i, j, value = 0, error = 0;
  for(i = 0, j = 0; hex[j] != '\0'; i = i + 4, j++) {
    if (hex[j] < 65) value = hex[j] - 48;
    else value = hex[j] - 55;
    error = tabela_conversora(value, i, bits);
    if (error) return 1;
  }
  bits[i] = '\0';
  return 0;
}

int hex_to_dec(char *hex, int *dec_pointer) {
  int error;
  char bits[256];
  error = hex_to_bin(hex, bits);
  if (error) return 1;
  error = bin_to_dec(bits, dec_pointer);
  if (error) return 1;
  return 0;
}

int dec_to_bin(int *dec_pointer, char *bits){
  int error;
  char hex[64];
  error = dec_to_hex(dec_pointer, hex);
  if (error) return 1;
  error = hex_to_bin(hex, bits);
  if (error) return 1;
  return 0;
}

int oct_to_dec(char *oct, int *dec_pointer){
  int i = 0, j = 0, expaux = 0, sum = 0, oct_value = 0;
  char asciioct = 48;
  while (oct[i] != '\0') {i++;}
  for(i = i - 1, j; oct[j] != '\0'; i--, j++) {
    asciioct = oct[j];
    switch (asciioct) {
      case 48: oct_value = 0; break;
      case 49: oct_value = 1; break;
      case 50: oct_value = 2; break;
      case 51: oct_value = 3; break;
      case 52: oct_value = 4; break;
      case 53: oct_value = 5; break;
      case 54: oct_value = 6; break;
      case 55: oct_value = 7; break;
      default: return 1;
    }
    expaux = expoct(i);
    sum = sum + (oct_value * expaux);
  }
  *dec_pointer = sum;
  return 0;
}

int dec_to_oct(int *dec_pointer, char *oct){
  if (!*dec_pointer) {oct[0] = '0'; oct[1] = '\0';}
  else {
    int counter = 0, ascii = 48, mod = 0, aux = *dec_pointer;
    while (aux > 0) {
      aux = aux / 8;
      counter++;
    }
    oct[counter]='\0';
    while (*dec_pointer > 0) {
      counter--;
      mod = (*dec_pointer % 8);
      oct[counter] = mod + ascii;
      *dec_pointer = (*dec_pointer / 8);
    }
  }
  return 0;
}

int generate_menu() {
  int operation = 0;
  printf("\n============MENU============\n"
    "1. Binario Para Decimal\n"
    "2. Binario Para Hexadecimal\n"
    "3. Hexadecimal Para Decimal\n"
    "4. Hexadecimal Para Binario\n"
    "5. Decimal Para Binario\n"
    "6. Decimal Para Hexadecimal\n"
    "7. Octal Para Decimal\n"
    "8. Decimal Para Octal\n"
    "\n"
    "Digite o Codigo Correspondente: ");
  scanf("%d", &operation); getchar();
  return operation;
}

int evaluate_operation(int operation) {
  int evaluation = 1, dec = 0, *dec_pointer;
  dec_pointer = &dec;
  char bits[256], hex[64], oct[85];

  switch (operation) {
    case 1:
      printf("Digite O Valor Em Binario: ");
      scanf("%s", bits); getchar();
      evaluation = bin_to_dec(bits, dec_pointer);
      printf("%d\n", dec);
    break;
    case 2:
      printf("Digite O Valor Em Binario: ");
      scanf("%s", bits); getchar();
      evaluation = bin_to_hex(bits, hex);
      printf("%s\n", hex);
    break;
    case 3:
      printf("Digite O Valor Em Hexadecimal: ");
      scanf("%s", hex); getchar();
      evaluation = hex_to_dec(hex, dec_pointer);
      printf("%d\n", dec);
    break;
    case 4:
      printf("Digite O Valor Em Hexadecimal: ");
      scanf("%s", hex); getchar();
      evaluation = hex_to_bin(hex, bits);
      printf("%s\n", bits);
    break;
    case 5:
      printf("Digite O Valor Em Decimal: ");
      scanf("%d", &dec); getchar();
      evaluation = dec_to_bin(dec_pointer, bits);
      printf("%s\n", bits);
    break;
    case 6:
      printf("Digite O Valor Em Decimal: ");
      scanf("%d", &dec); getchar();
      evaluation = dec_to_hex(dec_pointer, hex);
      printf("%s\n", hex);
    break;
    case 7:
      printf("Digite O Valor Em Octal: ");
      scanf("%s", oct); getchar();
      evaluation = oct_to_dec(oct, dec_pointer);
      printf("%d\n", dec);
    break;
    case 8:
      printf("Digite O Valor Em Decimal: ");
      scanf("%d", &dec); getchar();
      evaluation = dec_to_oct(dec_pointer, oct);
      printf("%s\n", oct);
    break;
    default:
      evaluation = 1;
    break;
  }
  return evaluation;
}

int main(int argc, char const *argv[]) {
  int operation, error;
  operation = generate_menu();
  error = evaluate_operation(operation);
  if (error) {
    printf ("Erro Ao Processar Dados, "
    "Certifique-Se Que Os Dados Inseridos Estao Corretos");
    return 1;}
  return 0;
}
