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
  if (artist_first_initial >= 97 && artist_first_initial <= 122) {
    int index = artist_first_initial - 97;
    library[index] = insert_ordered(library[index], song, artist);
  } else {
    library[26] = insert_ordered(library[26], song, artist);
  }
}

struct song_node * search_song(library library, char * song, char * artist) {
  char artist_first_initial = artist[0];
  if (artist_first_initial >= 97 && artist_first_initial <= 122) {
    int index = artist_first_initial - 96;
    struct song_node * section = library[index];
    return find_node(section, song, artist);
  } else {
    struct song_node * section = library[26];
    return find_node(section, song, artist);
  }
}

struct song_node * search_artist(library library, char * artist) {
  int index = artist[0] - 97;
  if (index < 0 || index > 25) {
    index = 26;
  }
  struct song_node * section = library[index];
  return find_author(section, artist);
}

void print_letter(library library, char letter) {
  // i just realized i didnt need to check :((((((
  int index = letter - 'a';
  if (index < 0 || index > 25) {
    index = 26;
  }
  printf("%c list\n", letter);
  print_list(library[index]);
}

void print_artist(library library, char * artist) {
  struct song_node * section = search_artist(library, artist);
  printf("Songs by %s: \n", artist);
  while(!(section == NULL || strcmp(section->artist, artist))) {
    printf("[%s : %s]\n", artist, section->name);
    section = section->next;
  }
  printf("\n");
}

void print_library(library library) {
  for (int i = 0; i < 27; i++) {
    if(library[i] != NULL) {
      print_letter(library, 97 + i);
    }
  }
}

void shuffle(library library, int total_songs) {
  if (total_songs > 0) {
    int section = rand() % 26; // index from 1 - 26;
    if(library[section] != NULL) {
      print_node(rand_node(library[section]));
      shuffle(library, total_songs - 1);
    } else {
      shuffle(library, total_songs);
    }
  }
}

void delete_song(library library, char * song, char * artist) {
  myremove(search_song(library, song, artist), artist, song);
}

void clear_library(library library) {
  for (int i = 0; i < 27; i++) {
    library[i] = free_list(library[i]);
  }
}
