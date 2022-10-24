//For all construct_*.c questions, please follow the tutorial/instructions here:
//https://docs.google.com/document/d/1HHhQQWp7ypdiqdGnPtWfoQIeqO3xIaSUfnZJLysILNU/edit?usp=sharing

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct snode {
  char str[101];
  int length;
  struct snode *next;
};

typedef struct snode node_t;

node_t * setup() {
    node_t * head ;
    //TODO:head declared for you
    //Allocate three more pointers
    //head for the first Node, and temporary pointers node1, node2 and node3
node_t *_node1, *_node2, *_node3;

    //Allocate three node pointees and store references to them in the three pointers
_node1 = malloc(sizeof(struct snode));
_node2 = malloc(sizeof(struct snode));
_node3 = malloc(sizeof(struct snode));

    //Dereference each pointer to store the appropriate number and string into the length and str fields in its pointee.
strcpy(_node1->str, "hello");
strcpy(_node2->str, "there");
strcpy(_node3->str, "prof");
_node1->length = strlen(_node1->str);
_node2->length = strlen(_node2->str);
_node3->length = strlen(_node3->str);
  
    //Dereference each pointer to access the .next field in its pointee, 
    //and use pointer assignment to set the .next field to point to the appropriate Node.
_node1->next = _node2;
_node2->next = _node3;
_node3->next = NULL;
head = _node1;  
    
   return head;
}

void teardown(node_t * head) {
    //TODO: free all dynamic memory you requested.
    //Please complete the prototype of teardown.
    //You are not allowed to use globals
if(head != NULL) 
{
teardown(head->next);
free(head);
}
}

void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    dump_all(head);
    teardown(head);
    return 0;
}
void dump_all(node_t * head) {
    printf("head -> ");
    node_t * cur = head;
    while(cur != NULL) {
        printf("%s ", cur->str);
	cur = cur->next;
    }
    printf("\ndone\n ");
}
