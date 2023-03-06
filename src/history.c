#include <string.h>
#include "stdio.h"
#include "history.h"

List* init_history(){
  List *hist = NULL;
  
};

void add_history(List *list, char *str){
  if(list==NULL){
    list.root.str = str;
    list.root.id = 0;
  }
  else{
    int count =0;
    while(list!=NULL){
      list++;
      count++;
    }
    list.root.str = str;
    list.root.id = count;
  }
};

char *get_history(List *list,int id){
  while(list.root.id!=id){
    list++;
  }
  return list.root.str;
};

void print_history(List *list){
  while(list!=NULL){
    printf("%d",list.root.str);
    list++;
  }
}

void free_history(List *list){
  //rework file to work with tokenizer

};
