 /*
 * Name: Joseph Di Lullo
 * Email: dilulloj@oregonstate.edu
 */

#include <stdlib.h>
#include <assert.h>
#include "list.h"


struct node
{
    void* val;
    struct node* next;
};


struct list
{
    struct node* head;
};


struct list* list_create()
{
    struct list* new_list = malloc(sizeof(struct list));  
    new_list -> head = NULL;                              
    return new_list;
}

void list_free(struct list* list)
{
   if (list -> head == NULL){      
        return;
    }
    struct node* temppointer = list -> head;
    struct node* temppointer2 = NULL;           
    while (temppointer != NULL){
        temppointer2 = temppointer;             
        temppointer = temppointer -> next;      
        free(temppointer2);                     
    }
    
    return;
}


void list_insert(struct list* list, void* val)
{
    struct node* new_node = malloc(sizeof(struct node));        
    new_node -> next = list -> head;                             
    list -> head = new_node;                                      
    new_node -> val = val;                                        
    return;
}

void list_remove(struct list* list, void* val, int (*cmp)(void* a, void* b))
{
    if (list -> head == NULL){              
        return;
    }
    struct node* temppointer = list -> head;
    struct node* temppointer2 = NULL;           
    int counter = 0;
    while (temppointer != NULL){                
        if (cmp(val, temppointer->val) == 0) {     
            temppointer2 = temppointer;             
            temppointer = temppointer -> next;     
            free(temppointer2);                     
        }
        else{
            temppointer = temppointer -> next;      
            counter++;
        }
    }
   
    return;
}

int list_position(struct list* list, void* val, int (*cmp)(void* a, void* b))
{
    if (list -> head == NULL){         
        return -1;
    }
    struct node* temppointer = list -> head;       
    int counter = 0;
    while (temppointer != NULL){                    
        if (cmp(val, temppointer->val) == 0) {          
            return counter;                             
        }
        else{
            temppointer = temppointer -> next;          
            counter++;
        }
    }
    return -1;
   
}

void list_reverse(struct list* list)
{
struct node *temp1, *temp2, *head;  
head = list -> head;               
	if (head != NULL){                
		temp2 = head -> next;         
        temp1 = head;
		head = head -> next;          
		temp1 -> next = NULL;           
		while (head != NULL)          
		{
			head = head -> next;         
			temp2 -> next = temp1;              
			temp1 = temp2;             
			temp2 = head;                      
		}
	    head = temp1;               

    }
    list -> head = head;               
    return;
}
