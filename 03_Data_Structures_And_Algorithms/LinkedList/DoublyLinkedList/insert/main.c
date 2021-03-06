#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef int boolean;
#define true  (1)
#define false (0)


typedef struct node{
  struct node* prev;
  int data;
  struct node* next;
}NODE;

NODE *head = NULL;

/* Prototypes */

NODE* create(int A[], int n);
void display(NODE* first);
int length(NODE* first);
void freeLinkedList(NODE* first);

/**
 * Inserts into globally defined doubly linkedList
 * @param int index you want to insert
 * @param int element you want to insert
 * @return boolean true if added successfully, otherwise false
 */
boolean insert(int index, int element){
  if( index < 0 || index > length(head) )
    return false;
  int i;  
  
  NODE* iterator;
  NODE* temp = (NODE*)malloc(sizeof(NODE*));
  temp->data = element;
 
  if( index == 0){
    temp->prev = NULL;
    temp->next = head;
    head->prev= temp;
    head = temp;
  }else{
    iterator = head;
    for(i = 1; i < index; i++)
      iterator = iterator->next; 	
    temp->prev = iterator;
    temp->next = iterator->next;
    if(iterator->next) 				// Be carefull, it may not exists if it is last node
      iterator->next->prev = temp;
    iterator->next = temp;
  }

return true;
}

// Unit Test
int main(){

  int A[] = {3,1,2,6,0,1,5,2,3};
  head = create(A, 9);
  printf("Length: %d\n", length(head) );
  display(head);
  insert(0, -111);
  display(head);
  insert(1, 555);
  display(head);
  insert(4, 444);
  display(head);
  insert(12, 121212);
  display(head);
  
  free(head);

return 0;
}

/**
 * Creates a doubly linkedlist with given array of elements
 */
NODE* create(int A[], int n){
  NODE* first, *t, *last;
  int i;
 
  first = (NODE*)malloc(sizeof(NODE));
  first->data = A[0];
  first->prev = first->next = NULL;
  last = first;

  for(i = 1; i < n; i++){

    t = (NODE*)malloc(sizeof(NODE));
    t->data = A[i];
    t->next = last->next;
    t->prev = last;
    last->next = t;
    last = t; 
  }

return first;
}

void display(NODE* first){

  while(first){
    printf("%d ", first->data);
    first = first->next;
  }
  printf("\n");
}

int length(NODE* first){
  int i = 0;
  while(first){
    first = first->next;
    i++;
  }
return i;
}

void freeLinkedList(NODE* first){
  NODE* temp;
  while(first){
    temp = first->next;
    free(first);
    first = temp;
  }
}

