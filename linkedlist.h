struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

void print_list(struct song_node * a);
struct song_node * insert_front(struct song_node * a, char * newauthor, char * song);
struct song_node * insert_ordered(struct song_node * a, char * newauthor, char * song);
struct song_node * free_list(struct song_node * a);
struct song_node * myremove(struct song_node *front, char * myauthor, char * myname);
struct song_node * find_node(struct song_node *a, char * myauthor, char * myname);
struct song_node * find_author(struct song_node *a, char * myauthor);
