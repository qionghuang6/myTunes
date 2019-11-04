#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

int main() {
  struct song_node * list;
  print_list(list);
  list = insert_front(list, "Kanye West", "Follow God");
  print_list(list);
  list = insert_front(list,"Post Malone", "Circles");
  print_list(list);
  list = insert_front(list,"Travis Scott", "HIGHEST IN THE ROOM");
  print_list(list);
  list = myremove(list, "Kanye West", "Follow God");
  print_list(list);
  print_list(find_author(list, "Post Malone"));
  list = insert_front(list,"Maroon 5", "Memories");
  print_list(list);
  list = myremove(list,"Maroon 5", "Memories");
  print_list(list);
  list = myremove(list,"Post Malone", "Circles");
  print_list(list);
  list = free_list(list);
  print_list(list);
  list = insert_ordered(list,"e","1");
  list = insert_ordered(list,"d","5");
  list = insert_ordered(list,"d","3");
  list = insert_ordered(list,"d","4");
  find_node(list,"d","3");
  print_list(list);
  insert_ordered(list,"f","2");
  print_list(list);
  list = free_list(list);
  list = insert_ordered(list,"a","0");
  print_list(list);
  return 0;
}
