#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history(){
  List *hist = (List*)malloc(sizeof(List));
  hist -> root = NULL;
  return hist;
  
};

void add_history(List *list, char *str){
  if(list->root == NULL){
    Item *item = (Item*)malloc(sizeof(Item));
    item->id = 0;
    char *to = (char *) malloc((strlen(str) + 1) * sizeof(char));
    for (int i=0; to[i] = str[i]; i++);
    item->str = to;
    list->root = item;
    return;
  }
  else{
    Item *temp = list->root;
    while(temp->next !=NULL){
      temp = temp->next;
      // printf(temp->str);
    }
    Item *item = (Item*)malloc(sizeof(Item));
    item->id = temp->id+1;
    char *to = (char *) malloc((strlen(str) + 1) * sizeof(char));
    for(int i=0;to[i]=str[i];i++);
    item->str = to;
    temp->next = item;
    // printf(list->root->next->str);
  }
};

char *get_history(List *list,int id){
  if(list == NULL){
    return 0;
  }
  if(list->root->id == id){
    return list->root->str;
  }
  Item *temp = list->root;
  while(temp != NULL && temp->id != id){
    temp = temp->next;
  }
  if(temp == NULL){
    return (char*) "Unavailable: No History";
  }
  return temp ->str;
};

void print_history(List *list){
  Item *temp = list->root;
  //printf(list->root->str);
  while(temp != NULL){
    printf("%d. %s\n",temp->id,temp->str);
    temp = temp->next;
  }
}

void free_history(List *list){
  free(list);
};
