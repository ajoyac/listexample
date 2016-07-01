#include <stdlib.h>
#include <stdio.h>

struct node{
  int val;
  struct node *next;
};
struct node* createnode(int val){
  struct node *head = malloc(sizeof(struct node));
  if (head){
    head->val=val;
    head->next=NULL;
    return head;
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
  ptr = createnode(val);
  ptr->next = head;
  return ptr;
}
void printlist(struct node *head) {
  struct node *curr;
  curr=head;
  if (curr){
    printf( "%d\n",curr->val );
    printlist(curr->next);
  }
}

int main(int argc, char const *argv[]) {
  struct node *head = NULL;
  int i;
  for (i=0;i<10;i++){
    head = addnode(head,i);
  }
  printlist(head);
  return 0;
}
