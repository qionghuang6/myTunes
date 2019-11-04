typedef struct song_node * library[27]; // now a library is an array of 27 song_nodes

void initialize_library(library library);
void add_song(struct song_node * song);
struct song_node * search_song(char * song, char * artist);
struct song_node * search_artist(char * artist);
void print_letter(char letter);
void print_artist(char * artist);
void print_library(library library);
void shuffle(library library, int total_songs);
void delete_song(char * song);
void clear_library(library library);
