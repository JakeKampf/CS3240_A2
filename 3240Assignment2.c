#include <stdlib.h>
#include <stdio.h> 
#include <dirent.h> 
#include <sys/stat.h>
#include <sys/types.h>
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
    q->size=0;
    q->front = q->rear = NULL; 
    return q; 

} 
  
void enQueue(struct Queue *q, char * element) 
{ 
    
    struct Node *temp = newNode(element); 
  
    if (q->rear == NULL) 
    { 
       q->size++;
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

int isEmpty(struct Queue * q)
{
    if(q->size==0){
        return 1;
    }
    else{
        return 0;
    }
}
void checkType(struct Queue * q, char * input){
//check the if directory or regular file
//if directory, enqueue it to be explored once the current directory is full exlpored
//if regular file, print it out and move to the next
struct stat	buf; 

if (lstat(input, &buf) < 0) { 
					 

		}

		if (S_ISREG(buf.st_mode)) {
            
			printf("FILE: %s\n",input); 
        }

		if (S_ISDIR(buf.st_mode) && strcmp(input,".")!=0 && strcmp(input,"..")!=0)  {   
            printf("DIRECTORY: %s\n",input);   

            enQueue(q,input); 
        }

		

}
void buildQueue(char * input)
{
    //lstat determines if it is a file or a directory
    //open directory, explore all files in the directory, if another directory is found, add to queue, if 
    //if it is a regular file
	// char		*ptr; 

    struct Queue * q = createQueue();
    DIR             *dp;
    struct dirent   *dirp;  
    //char * buf=""; 
           if (input == NULL)
               err_quit("usage: ls directory_name");
           if ((dp = opendir(input)) == NULL){
               err_sys("can’t open %s, be sure to include '~/' at the beginning of your path.\n", input);
           }
           else if((dp = opendir(input))!= NULL){
               if(chdir(input) == 0){ 
                getcwd(input,sizeof(input));                
                enQueue(q, input);
               }
           } 
            
           while (!isEmpty(q)) {
                
             if(q->size>=1){   
               dp = opendir(deQueue(q)->element); 
               dirp = readdir(dp);
             }
                while((dirp = readdir(dp)) != NULL){
                checkType(q, dirp->d_name); 
  
                }

           }
               
     closedir(dp);
	 	
		
	
}  

int main(int argc, char** argv) 
{ 
     
      buildQueue(argv[1]);


    return 0; 
}
