#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedlist.h"
#include "tunelibrary.h"

void print_list(struct song_node * a){
  printf("[ ");
  struct song_node * curr = a;
  //loop through the list and print each node
  while (curr != NULL) {
    printf("%s: ", curr->artist);
    printf("%s; ", curr->name);
    curr = curr->next;
  }
  printf("]\n");
}

struct song_node * insert_front(struct song_node * a, char * newauthor, char * song){
  //allocate memory for new node
  struct song_node * newFront = malloc(sizeof(struct song_node));
  //copy data into new node
  strcpy(newFront->name,song);
  strcpy(newFront->artist,newauthor);
  //set the newnode's next value to be the front of the list
  newFront->next = a;
  //return node as the front of the list
  return newFront;
}

struct song_node * insert_ordered(struct song_node * a, char * newauthor, char * song){
  //set up variables for looping through and for tracking the last node changed
  struct song_node * curr = a;
  struct song_node * last_node = NULL;
  for (; curr != NULL; curr = curr->next) {
    //loops through and checks if the author is already too big, if so, add new node to
    //the front of the node and then set the previous node to this node
    if(strcmp(newauthor,curr->artist ) < 0 ||
    (strcmp(newauthor,curr->artist ) == 0 && strcmp(song,curr->name ) < 0)){
      printf("HI!\n");
      //for if we're at the front of the list
      if(last_node == NULL){
          a = insert_front(curr, newauthor, song);
      } else{
          last_node->next = insert_front(curr, newauthor, song);
      }
      break;
    }
    //if we've already reached the end of the list, then just add the node
    if(curr->next == NULL){
      curr->next = malloc(sizeof(struct song_node));
      strcpy(curr->next->name,song);
      strcpy(curr->next->artist,newauthor);
      break;
    }
    last_node = curr;
  }
  //if the list was empty to begin with, just add the node to the front
  if(a == NULL){
    a = insert_front(a,newauthor,song);
  }
  return a;
}
struct song_node * find_node(struct song_node *a, char * myauthor, char * myname){
    //loops trhough to the find the right node and then print it
    for (; a != NULL; a = a->next) {
      if(strcmp(a->artist,myauthor) == 0 && strcmp(a->name,myname) == 0){
        printf("node found! %s: %s\n", a->artist, a->name);
        return a;
      }
    }
    printf("Node not found\n"  );
    return a;
}
struct song_node * find_author(struct song_node *a, char * myauthor){
  for (; a != NULL; a = a->next) {
      if(strcmp(a->artist,myauthor) == 0){
        printf("Artist found! %s: First song: %s\n", a->artist, a->name);
        return a;
      }
    }
    printf("Author not found\n"  );
    return a;
}
struct song_node * free_list(struct song_node * a){
  //loops through and frees all the nodes until it hits null
  while(a != NULL){
    printf("freeing node: %s, %s\n", a->artist, a->name);
    struct song_node * next = a->next;
    free(a);
    a = next;
  }
  return a;
}

size_t list_length(struct song_node * a){
  size_t size = 0;
  for (; a != NULL; a = a->next) {
    size++;
  }
  return size;
}

struct song_node * rand_node(struct song_node * a){
  size_t rand_size = rand() % list_length(a);
  for (size_t i = 0; i < rand_size; i++) {
    a = a->next;
  }
  printf("Random Node found: %s: %s\n", a->artist, a->name);
  return a;
}

struct song_node * myremove(struct song_node *front, char * myauthor, char * myname){
  struct song_node * curr = front;
  for (; curr != NULL; curr = curr->next) {
    //if we are already the right node, free it, for if its the front
    if(strcmp(curr->artist,myauthor)==0 && strcmp(curr->name,myname)==0){
      struct song_node * next = curr->next;
      free(curr);
      curr = next;
      front = next;
    }
    //if the next node isn't null and its the right one, then free the next one and rejoin the list
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
