#include <stdlib.h>
#include <stdio.h>

struct node{
  int val;
  struct node *prev;
  struct node *next;
};
struct node* createnode(int val){
  struct node *ptr = malloc(sizeof(struct node));
  if (ptr){
    ptr->val=val;
    ptr->prev=NULL;
    ptr->next=NULL;
    return ptr;
  }
  else{
    fprintf(stderr, "%s\n", "Unable to allocate memory");
    return NULL;
  }
}
struct node* addnode(struct node* head, int val){
  struct node *ptr=NULL;
  if(!head){
    return createnode(val);
  }
  ptr = head;
  while(ptr->next){
    ptr = ptr->next;
  }
  ptr->next = createnode(val);
  ptr->next->prev=ptr;
  return ptr->next;
}
void printlistright(struct node *head) {
  struct node *curr;
  curr=head;
  if (curr){
    printf( "%d\n",curr->val );
    printlistright(curr->next);
  }
}
void printlistleft(struct node *head) {
  struct node *curr;
  curr=head;
  if (curr){
    printf( "%d\n",curr->val );
    printlistleft(curr->prev);
  }
}

int main(int argc, char const *argv[]) {
  struct node *head = NULL, *last = NULL;
  int i;
  head = addnode(head,0);
  for (i=1;i<10;i++){
     last = addnode(head,i);
  }
  printlistright(head);
  printlistleft(last);
  return 0;
}
