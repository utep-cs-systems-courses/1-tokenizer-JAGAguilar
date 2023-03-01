#include "stdio.h"
#include "string.h"
#include "tokenizer.c"


int main (){
  int b = non_space_char('b'); 
  printf("%d",b);
  char *c = "b";
  char d =  *token_start(c);
  printf("%d",d);
  char str[500]; //large enough to hold a long string
  char *quit = "q";
  while(1) {
    printf("$ ");
    fgets(str,500, stdin); //gets input and stores it in str
    if(strcmp(str,quit)==10){ //uses built in string comparison to check if q
      printf("UI Terminated\n"); //if q Terminates loop
      return(0);
    }
    fputs(str,stdout); //regurgitates input
  }
}
