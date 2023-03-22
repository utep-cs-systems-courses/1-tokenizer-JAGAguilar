#include "stdio.h"
#include "string.h"
#include <stdlib.h>
#include "tokenizer.c"
#include "tokenizer.h"
#include "history.h"
#include "history.c"


int main (){
  List* hist = init_history();
  char str[500]; //large enough to hold a long string
  char *quit = "q";
  char *printHist = "p";
  char *clearHist = "f";
  char *speHist = "ps";
  printf("To exit the UI type 'q', to clear history type 'f', to print a specific previous phrase type 'ps'or to print type 'p'.\n");
  while(1) {
    printf("$ ");
    fgets(str,500, stdin); //gets input and stores it in str
    if(strcmp(str,quit)==10){ //uses built in string comparison to check if q
      printf("UI Terminated\n"); //if q Terminates loop
      return(0);
    }
    if(strcmp(str,speHist)==10){
      printf("$ Input ID (INTEGERS ONLY):");
      fgets(str,500,stdin);
      printf(get_history(hist,atoi(str)));
    }
    if(strcmp(str,clearHist)==10){
      free_history(hist);
    }
    if(strcmp(str,printHist)==10){
      print_history(hist);
    }
    else{
      add_history(hist,str);
    }
  }
}
