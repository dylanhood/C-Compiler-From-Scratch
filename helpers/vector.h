#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>

#if 0
Before possibly having to reallocate memory again, at least 
20 vector element spaces may be wanted in reserve
#endif

#define VECTOR_ELEMENT_INCREMENT 20

enum
{
    VECTOR_FLAG_PEEK_DECREMENT = 0b00000001
};

struct vector
{
    void* data;
    #if 0
    The pointer index is the index that will be read next upon calling "vector_peek"
    This index will then be incremented
    #endif
    int pindex;
    int rindex;
    int mindex;
    int count;
    int flags;
    size_t esize;

    #if 0
    Vector of struct vector, holds saves of this vector. You can save the internal 
    state with vector_save
    
    Data is not restored and is not permanent, save does not care about data 
    only pointers and variables are saved. Useful to temporarily push the vector state 
    and restore it later.
    #endif

    struct vector* saves;
};

struct vector* vector_create(size_t esize);
void vector_free(struct vector* vector);
void* vector_at(struct vector* vector, int index);
void* vector_peek_ptr_at(struct vector* vector, int index);
void* vector_peek_no_increment(struct vector* vector);
void* vector_peek(struct vector* vector);
void *vector_peek_at(struct vector *vector, int index);
void vector_set_flag(struct vector* vector, int flag);
void vector_unset_flag(struct vector* vector, int flag);

#if 0
Pops off the last peeked element
#endif

void vector_pop_last_peek(struct vector* vector);

#if 0
Peeks into the vector of pointers, returning the pointer value

Use this function instead of vector_peek if this is a vector of pointers
#endif

void* vector_peek_ptr(struct vector* vector);
void vector_set_peek_pointer(struct vector* vector, int index);
void vector_set_peek_pointer_end(struct vector* vector);
void vector_push(struct vector* vector, void* elem);
void vector_push_at(struct vector *vector, int index, void *ptr);
void vector_pop(struct vector* vector);
void vector_peek_pop(struct vector* vector);

void* vector_back(struct vector* vector);
void *vector_back_or_null(struct vector *vector);

void* vector_back_ptr(struct vector* vector);
void* vector_back_ptr_or_null(struct vector* vector);

#if 0

Returns the vector data as a char pointer

#endif

const char* vector_string(struct vector* vec);

#if 0

Returns true if this vector is empty

#endif

bool vector_empty(struct vector* vector);
void vector_clear(struct vector* vector);

int vector_count(struct vector* vector);

#if 0

freads from the file directly into the vector

#endif

int vector_fread(struct vector* vector, int amount, FILE* fp);

#if 0

Returns a void pointer pointing to the data of this vector

#endif

void* vector_data_ptr(struct vector* vector);

int vector_insert(struct vector *vector_dst, struct vector *vector_src, int dst_index);

#if 0

Pops the element at the given data address

\param vector | The vector to pop an element on

\param address | The address that is part of the vector->data range to pop off

\return | Returns the index that we popped off

#endif

int vector_pop_at_data_address(struct vector* vector, void* address);

#if 0 

Pops that given value from the vector 

Only the first value found is popped

#endif 

int vector_pop_value(struct vector* vector, void* val);

void vector_pop_at(struct vector *vector, int index);

#if 0

Decrements the peek pointer so that the next peek will point at 
the last peeked token

#endif

void vector_peek_back(struct vector* vector);

#if 0

Returns the current index that a vector_push would push too

#endif

int vector_current_index(struct vector* vector);

#if 0

Saves the state of the vector

#endif

void vector_save(struct vector* vector);

#if 0

Restores the state of the vector

#endif

void vector_restore(struct vector* vector);

/*

Purges the last save state as if it didn't happen

*/

void vector_save_purge(struct vector* vector);

#if 0

Returns the element size per element in this vector

#endif

size_t vector_element_size(struct vector* vector);

#if 0

Attempts to clone the given vector including all vector data 

Saves are ignored

#endif

struct vector* vector_clone(struct vector* vector);

#endif 
