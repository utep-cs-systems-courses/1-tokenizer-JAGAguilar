#include "tokenizer.h"
#include "stdio.h"
#include <string.h>

//the ; after each function is to remind myself where it ends
int space_char(char c){
  if(c==' '||c=='\t' ){
    return 1;
  }
  return 0;
};

int non_space_char(char c){
  if(c == '\0'){
    return 0;
  }
  if(!space_char(c)){
    return 1;
  }
  return 0;
};

char *token_start(char *str){
  while(space_char(*str)){
    str++;
  }
  if(*str == '\0'){
    return NULL;
  }
  return str;
};

char *token_terminator(char *token){
  while(non_space_char(*token)){
    token++;
  }
  return token;
};

int count_tokens(char *str){
  int count = 0;
  str = token_start(str);
  while(str != NULL){
    count++;
    str = token_terminator(str);
  }
  return count;
};

char *copy_str(char *inStr, short len){
  char *str = (char*)malloc(sizeof(char) * len);
  char *temp_String = str;
  len--;
  while(len>=0){
    *temp_String = *inStr;
    temp_String++;
    inStr++;
  }
  str;
};

char **tokenize(char* str){
  
};
