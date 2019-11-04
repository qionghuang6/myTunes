#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedlist.h"
#include "tunelibrary.h"

void add_song(struct song_node * song) {
  char artist_first_initial = (song->artist)[0];
  printf("%c\n", artist_first_initial);
}
