#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedlist.h"
#include "tunelibrary.h"

void initialize_library(library library) {
  for (int i = 0; i < 27; i++) {
    library[i] = NULL;
  }
}

void add_song(struct song_node * song) {
  char artist_first_initial = (song->artist)[0];
  if (artist_first_initial >= 65 && artist_first_initial <= 90) {
    int index = artist_first_initial - 64; // this is for uppercase artist names
    //library[index].insert_front(song, song->artist, song->name);
    printf("%d\n",sizeof(library));
  }
}
