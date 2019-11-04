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

void add_song(library library, char* song, char* artist) {
  char artist_first_initial = artist[0];
  // this is for uppercase artist names
  if (artist_first_initial >= 65 && artist_first_initial <= 90) {
    int index = artist_first_initial - 64;
    library[index] = insert_ordered(library[index], song, artist);
  } if else (artist_first_initial >= 97 && artist_first_initial <= 122) {
    int index = artist_first_initial - 96;
    library[index] = insert_ordered(library[index], song, artist);
  } else {
    library[26] = insert_ordered(library[26], song, artist);
  }
}

struct song_node * search_song(library library, char * song, char * artist) {
  char artist_first_initial = artist[0];
  // this is for uppercase artist names
  if (artist_first_initial >= 65 && artist_first_initial <= 90) {
    int index = artist_first_initial - 64;

  }
  // this is for lowercase artist names
  if (artist_first_initial >= 97 && artist_first_initial <= 122) {
    int index = artist_first_initial - 96;

  }
}
