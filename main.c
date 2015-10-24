#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "types.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

int digitToInt(char c) {
  if (c >= 'a' && c <= 'f') {
    return c - 'a' + 10;
  } else {
    return c - '0';
  }
}

int stringToNum(char *s, int base, char terminator) {
  int sum = 0;
  while (*s != terminator && *s != tolower(terminator)) {
    sum *= base;
    sum += digitToInt(tolower(*s));
    s++;
  }
  return sum;
}

int main(void) {
  int ntoken;

  ntoken = yylex();

  while (ntoken) {
    if (ntoken == OCTAL) {
      printf("%d\n", stringToNum(yytext, 8, 'B'));
    } else if (ntoken == HEX) {
      printf("%d\n", stringToNum(yytext, 16, 'H'));
    } else if (ntoken == DECIMAL) {
      printf("%d\n", atoi(yytext));
    }
    ntoken = yylex();
  }
  return 0;
}
