#include <stdlib.h>
#include <stdio.h> 
#include <dirent.h> 
#include <sys/param.h>
#include "apue.h"
#include "error.c"
//Tanner's error, when concatinating path, concatinate the path and the slash
struct Node 
{ 
    char * element; 
    struct Node *next; 
}; 
  
struct Queue 
{ 
    int size;
    struct Node *front, *rear; 
}; 
  
struct Node* newNode(char * element) 
{ 
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node)); 
    temp->element = element; 
    temp->next = NULL; 
    return temp;  
} 
  
struct Queue *createQueue() 
{ 
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue)); 
    q->front = q->rear = NULL; 
    return q; 
} 
  
void enQueue(struct Queue *q, char * element) 
{ 
    struct Node *temp = newNode(element); 
  
    if (q->rear == NULL) 
    { 
       q->front = q->rear = temp; 
       return; 
    } 
    q->size++;
    q->rear->next = temp; 
    q->rear = temp; 
} 
  

struct Node *deQueue(struct Queue *q) 
{ 
    if (q->front == NULL) 
       return NULL; 
  

    struct Node *temp = q->front; 
    q->front = q->front->next; 
    
    if (q->front == NULL) 
       q->rear = NULL; 

       q->size--;
    return temp; 
} 
void buildQueue(char * input){
  
    
}  
int main(int argc, char** argv) 
{ 
    
buildQueue(argv[1]);

    return 0; 
}
