#include <string.h>
#include "erl_nif.h"

int sum(int a, int b) {
  return a+b;
}

int factorial(int a){
  if(a == 0) return 1;
  else return a*factorial(a-1);
}

int string_length(char* string) {
  return strlen(string);
}

char * to_string(ErlNifBinary bin) {
  return bin.data;
}