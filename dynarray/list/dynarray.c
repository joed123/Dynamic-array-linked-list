/*
 * Name: Joseph Di Lullo
 * Email: dilulloj@oregonstate.edu
 */

#include <stdlib.h>
#include <assert.h>
#include "dynarray.h"

struct dynarray
{
    void** data;
    int size;
    int capacity;
};

struct dynarray* dynarray_create()
{
    struct dynarray *s = malloc(sizeof(struct dynarray));   
    void** array = malloc(2 * sizeof(void*));               
    s -> data = array;
    s -> size = 0;                                          
    s -> capacity = 2;
    return s;
}


void dynarray_free(struct dynarray* da)
{
    free(da->data);                           
    return;
}


int dynarray_size(struct dynarray* da)
{
    return da->size;                    
}


void dynarray_insert(struct dynarray* da, void* val)
{
    int c = da -> capacity;
    int s = da -> size;                        
    if (s < c){ 
        da -> data[s] = val;                        
        da -> size++;
    }
    else {
        void** temparray = malloc(2 * s * sizeof(void*));              
        da -> capacity = 2 * s;                                      
        int looping = s;                                               
        while(looping > 0){
            temparray[looping - 1] = da -> data[looping - 1];       
            looping--;
        }
        dynarray_free(da);                                              
        da-> data = temparray;                                          
        da -> data[s] = val;                                            
        da -> size++;
    }
    return;
}

void dynarray_remove(struct dynarray* da, int idx)
{
    int s = da -> size;                     
    void** temparray = malloc(s * sizeof(void*));      
    int looping = 0;
    int counter = 0;
        while(looping < s){
            if (looping == idx){                
            }
            else{
                temparray[counter] = da -> data[looping];   
                counter++;
            }
            looping++; 
        }
    dynarray_free(da);                             
    da-> data = temparray;                             
    da -> size--;
}

void* dynarray_get(struct dynarray* da, int idx)
{
    return da -> data[idx];             
}

void dynarray_set(struct dynarray* da, int idx, void* val)
{
    da -> data[idx] = val;          
    return; 
}
