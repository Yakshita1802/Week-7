//For all construct_*.c questions, please follow the tutorial/instructions here:
//https://docs.google.com/document/d/1HHhQQWp7ypdiqdGnPtWfoQIeqO3xIaSUfnZJLysILNU/edit?usp=sharing

#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    char * value; //must use dynamic allocation 
    struct node* next;
} 
node_t;

node_t * construct_3_strs() {
    //return NULL;//Your code here. Currently return NULL just to pass compiler, please edit as needed.
	
  //I establish three distinct nodes and use malloc to dynamically allocate memory.
node_t* x = (node_t*)malloc(sizeof(node_t));
node_t* y = (node_t*)malloc(sizeof(node_t));
node_t* z = (node_t*)malloc(sizeof(node_t));
	
//I give each of the three nodes its respective values.
x->value = "CS604";
y->value = "is";
z->value = "awesome";
	
//I set the.next field to point to the proper Node using pointer assignment.
x->next = y;
y->next = z;
z->next = x;

return x; // removed NULL and I return starting node x
}

//You can ignore the following code for testing
int dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * x = construct_3_strs();
    return dump_all(x);

}

int dump_all(node_t * x) {
    printf("x -> %s", x->value);
    node_t * y = x->next;
    printf(" %s", y->value);
    node_t * z = y->next;
    printf(" %s\n", z->value);
    if(z->next != x) {
    	printf("failed");
	return -1;
    } else {
        return 0;
    }
}
