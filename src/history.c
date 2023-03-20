#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history(){
  List *hist = (List*)malloc(sizeof(List));
  return hist;
  
};

void add_history(List *list, char *str){
  if(list->root == 0){
    Item *item = (Item*)malloc(sizeof(Item));
    item->id = 0;
    char *start = token_start(str);
    item->str = copy_str(start,token_terminator(str)-start);
    list->root = item;
    return;
  }
  else{
    Item *temp = list->root;
    while(temp->next !=0){
      temp = temp->next;
    }
    Item *item = (Item*)malloc(sizeof(Item));
    item->id = temp->id+1;
    char *start = token_start(str);
    item->str = copy_str(start,token_terminator(str)-start);
    temp->next = item;
  }
};

char *get_history(List *list,int id){
  if(list == 0){
    return 0;
  }
  if(list->root->id == id){
    return list->root->str;
  }
  Item *temp = list->root;
  while(temp != 0 && temp->id != id){
    temp = temp->next;
  }
  if(temp == 0){
    return (char*) "Unavailable: No History";
  }
  return temp ->str;
};

void print_history(List *list){
  Item *temp = list->root;
  if(temp == 0){
    printf("Unavailable: No History");
  }
  else{
    while(temp != 0){
      printf("%d. %s\n",temp->id,temp->str);
      temp = temp->next;
    }
  }
}

void free_history(List *list){
  free(list);
};
