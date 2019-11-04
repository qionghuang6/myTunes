#include <stdlib.h>
#include <stdio.h>
#include "tunelibrary.h"
#include "linkedlist.h"
#include <time.h>

int main() {
  srand(time(NULL));
  struct song_node * list;

  printf("LINKED LIST TESTS\n==============\n");
  list = insert_front(list, "Kanye West", "Follow God");
  list = insert_front(list,"Post Malone", "Circles");
  list = insert_front(list,"Travis Scott", "HIGHEST IN THE ROOM");
  list = insert_front(list,"Selena Gomez", "Lose You To Love Me");
  list = insert_front(list,"Maroon 5", "Memories");
  printf("\nTesting Print List:\n" );
  print_list(list);

  printf("==============\n\nTesting Print NOde\n");
  print_node(list);

  printf("==============\n\nTesting Find Node\n");
  printf("Looking for Kanye West: Follow God\n");
  find_node(list,"Kanye West", "Follow God");
  printf("Looking for Travis Scott: HIGHEST IN THE ROOM\n");
  find_node(list,"Travis Scott", "HIGHEST IN THE ROOM");

  printf("==============\n\nTesting Find Artist\n");
  printf("Looking for Kanye West\n");
  print_list(find_author(list, "Kanye West"));
  printf("Looking for Selena Gomez\n");
  print_list(find_author(list, "Selena Gomez"));
  printf("Looking for John-Alf Dyrland Weaver\n");
  print_list(find_author(list, "John-Alf Dyrland Weaver"));

  printf("==============\n\nWe didn't use a songcmp\n");
  printf("===============\n\n Testing random\n");
  print_node(rand_node(list));
  print_node(rand_node(list));
  print_node(rand_node(list));
  print_node(rand_node(list));

  printf("===============\n\n Testing remove\n");
  printf("Removing Kanye West: Follow God\n" );
  list = myremove(list, "Kanye West", "Follow God");
  print_list(list);
  printf("Removing Maroon 5: Memories\n");
  list = myremove(list,"Maroon 5", "Memories");
  print_list(list);
  printf("Removing Post Malone: Circles\n" );
  list = myremove(list,"Post Malone", "Circles");

  printf("===============\n\n Testing free list\n");
  list = free_list(list);
  print_list(list);
  printf("===============\n");
  return 0;
}
