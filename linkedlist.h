struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

struct song_node {char author[64]; char name[64]; struct song_node * next; };
void print_list(struct song_node * a);
struct song_node * insert_front(struct song_node * a, struct song_node b);
struct song_node * insert_ordered(struct song_node * a, struct song_node b);
struct song_node * free_list(struct song_node * a);
struct song_node * myremove(struct song_node *front, struct song_node data);
