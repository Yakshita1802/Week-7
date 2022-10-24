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
node_t *_teardown = head;
while(head != NULL){
_teardown = head->next;
free(head);
head = _teardown;
}
}
void add(node_t ** head, char * str, int length){
    //TODO: copy add func from task2
  node_t * _node_add =(node_t*)malloc(sizeof(node_t));
strcpy(_node_add->str, str);
_node_add->length = length;
_node_add->next = *head;
*head = _node_add;
}
void delete_node_at(node_t ** head, int idx) {
    //TODO: implement delete a node based on index
	//deletes a node at index idx, which ranges from zero to the length of the list - 1.
node_t *_head = *head;
node_t *_teardown = *head;
if(idx == 0){ //index is 0, thus I must update the head.
if(_head){
*head = (_head->next);
free(_head);
}
else printf("No index is available \n");

}
else{
int i;
for(i=0;_head && i<idx;i++){
_teardown = _head;
_head = _head->next;
}
if(i == idx){
_teardown->next = _head->next;
free(_head);
}
else printf("No index is available. \n");
}
} 
void delete_node_key(node_t **head, char * key) {
    //TODO: implement delete a node based on key
    //given a certain key, find and delete. 
node_t *_head = *head;
node_t *_teardown = _head;
while(_head){
//printf("match - %d ",strcmp(h->str,key));
if(strcmp(_head->str,key)==0){

if(_teardown == _head){ // key is found at head....
*head = (_head->next);
free(_head);
}
else{
_teardown->next = _head->next;
free(_head);
}
}
_teardown = _head;
_head = _head->next;

}
}

// to test
void print(node_t *head){
int i = 0;
while(head){
printf("%d %s \n",i++,head->str);
head = head->next;
}
}

void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    add(&head, "hi", 2);
    delete_node_key(&head, "prof");
    delete_node_at(&head, 0);
    dump_all(head);
    teardown(head);
    return 0;
}

void dump_all(node_t * head) 
{
    printf("head -> ");
    node_t * cur = head;
    while(cur != NULL) {
        printf("%s ", cur->str);
	cur = cur->next;
    }
    printf("\ndone\n ");
}