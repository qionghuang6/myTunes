#include <stdlib.h>
#include <stdio.h>
#include "funcs.h"

void print_list(struct song_node * a){
  printf("[");
  struct song_node * curr = a;
  while (curr != NULL) {
    printf(" %d", curr->i);
    curr = curr->next;
  }
  printf(" ]\n");
}

struct song_node * insert_front(struct song_node * a, struct song_node b){
  struct song_node * newFront = malloc(sizeof(struct song_node));
  newFront->i = b;
  newFront->next = a;
  return newFront;
}

struct song_node * free_list(struct song_node * a){
  while(a != NULL){
    printf("freeing node: %d\n", a->i);
    struct song_node * next = a->next;
    free(a);
    a = next;
  }
  return a;
}

struct song_node * myremove(struct song_node *front, struct song_node data){
  struct song_node * curr = front;
  for (; curr != NULL; curr = curr->next) {
    if(curr->i == data){
      struct song_node * next = curr->next;
      free(curr);
      curr = next;
      front = next;
    }
    else if(curr-> next != NULL ){
      struct song_node * nextnext = curr->next->next;
      if(curr->next->i == data){
        free(curr->next);
        curr->next = nextnext;
      }
    }
  }
  return front;
}
