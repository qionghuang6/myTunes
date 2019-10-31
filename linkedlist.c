#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedlist.h"
#include "tunelibrary.h"

void print_list(struct song_node * a){
  printf("[ ");
  struct song_node * curr = a;
  while (curr != NULL) {
    printf("%s: ", curr->artist);
    printf("%s; ", curr->name);
    curr = curr->next;
  }
  printf("]\n");
}

struct song_node * insert_front(struct song_node * a, char * newauthor, char * song){
  struct song_node * newFront = malloc(sizeof(struct song_node));
  strcpy(newFront->name,song);
  strcpy(newFront->artist,newauthor);
  newFront->next = a;
  return newFront;
}

struct song_node * insert_ordered(struct song_node * a, char * newauthor, char * song){
  struct song_node * curr = a;
  for (; curr != NULL; curr = curr->next) {
    if(strcmp(newauthor,curr->artist ) < 0){
      if(curr == a){
        a = insert_front(a,newauthor,song);
      }else{
          curr = insert_front(curr, newauthor, song);
      }
      break;
    }
  }
  return a;
}

struct song_node * free_list(struct song_node * a){
  while(a != NULL){
    printf("freeing node: %s, %s\n", a->artist, a->name);
    struct song_node * next = a->next;
    free(a);
    a = next;
  }
  return a;
}

struct song_node * myremove(struct song_node *front, char * myauthor, char * myname){
  struct song_node * curr = front;
  for (; curr != NULL; curr = curr->next) {
    if(strcmp(curr->artist,myauthor)==0 && strcmp(curr->name,myname)==0){
      struct song_node * next = curr->next;
      free(curr);
      curr = next;
      front = next;
    }
    else if(curr-> next != NULL ){
      struct song_node * nextnext = curr->next->next;
      if(strcmp(curr->next->name, myname) == 0 && strcmp(curr->next->artist,myauthor)==0){
        free(curr->next);
        curr->next = nextnext;
      }
    }
  }
  return front;
}
