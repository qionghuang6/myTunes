#include <stdlib.h>
#include <stdio.h>
#include "tunelibrary.h"
#include "linkedlist.h"
#include <time.h>

int main() {
  srand(time(NULL));
  struct song_node * list = NULL;

  print_list(list);
  printf("LINKED LIST TESTS\n==============\n");
  list = insert_ordered(list, "Kanye West", "Follow God");
  list = insert_ordered(list,"Post Malone", "Circles");
  list = insert_ordered(list,"Travis Scott", "HIGHEST IN THE ROOM");
  list = insert_ordered(list,"Selena Gomez", "Lose You To Love Me");
  list = insert_ordered(list,"Maroon 5", "Memories");
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

  print_list(list);
  printf("===============\n\n Testing free list\n");
  list = free_list(list);
  print_list(list);
  printf("===============\n");

  printf("-------LIBRARY TEST-------\n");

  library mytunes;
  initialize_library(mytunes);
  // I STOLE THIS FROM WILLIAM :))))) i got lazy
  add_song(mytunes, "m-song", "a-artist");
  add_song(mytunes, "m-song", "b-artist");
  add_song(mytunes, "n-song", "b-artist");
  add_song(mytunes, "o-song", "b-artist");
  add_song(mytunes, "r-song", "z-artist");
  add_song(mytunes, "s-song", "z-artist");
  add_song(mytunes, "t-song", "zoo-artist");
  add_song(mytunes, "t-song", "1-artist");
  add_song(mytunes, "u-song", "3-artist");

  printf("Testing Print library\n");
  print_library(mytunes);
  //
  printf("Testing Print letter\n");
  print_letter(mytunes, 'b');

  printf("Testing find\n");
  printf("looking for [zoo-artist : t-song]\n");
  search_song(mytunes, "t-song", "zoo-artist");
  printf("looking for [zoo : t]\n");
  search_song(mytunes, "t", "zoo");

  printf("Testing remove\n");
  printf("removing : [zoo-artist : t-song]\n");
  delete_song(mytunes, "t-song", "zoo-artist");
  print_library(mytunes);

  printf("Testing Print artist\n");
  print_artist(mytunes, "b-artist");

  printf("Testing shuffle\n");
  shuffle(mytunes, 5);

  printf("Testing clear_library\n");
  print_library(mytunes);
  clear_library(mytunes);
  print_library(mytunes);
  return 0;
}
