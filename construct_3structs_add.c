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
    //TODO:copy setup func from previous task
  //x for the first Node, and temporary pointers y and z for the other two Nodes.
node_t * head = (node_t*)malloc(sizeof(node_t));
node_t * _node1 = (node_t*)malloc(sizeof(node_t));
node_t * _node2 = (node_t*)malloc(sizeof(node_t));
node_t * _node3 = (node_t*)malloc(sizeof(node_t));
  
  //Dereference each pointer to store the appropriate number and string into the length and str fields in its pointee.
strcpy(_node1->str, "hello");
_node1->length = 5;
strcpy(_node2->str, "there");
_node2->length =5;
strcpy(_node3->str, "prof");
_node3->length = 4;
  //and use pointer assignment to set the .next field to point to the appropriate Node. 
head->next = _node1;
_node1->next = _node2;
_node2->next =_node3;
_node3->next = NULL;
 
  return head;
}
void teardown(node_t * head) {
    //TODO: free all dynamic memory you requested.
    //Please complete the prototype of teardown.
    //You are not allowed to use globals
while(head != NULL)
{
free(head);
head = head->next;
}
}
void add(node_t ** head, char * str, int length){
    //TODO: implement add to add a new node to front, pointed by head
node_t * _node_add =(node_t*)malloc(sizeof(node_t));
strcpy(_node_add->str, str);
_node_add->length = length;
_node_add->next = *head;
*head = _node_add;  
}

void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    add(&head, "hi", 2);
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