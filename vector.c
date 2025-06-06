#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "vector.h"



struct Vector {
    unsigned int size;
    unsigned int capacity;
    void **data;
};


Vector *vector() {
    // initialize a vector container
    Vector *v = malloc(sizeof(struct Vector));

    v->capacity = INIT_VEC_SIZE;
    v->size = 0;
    v->data = malloc(sizeof(void *) * INIT_VEC_SIZE);

    return v;
}


void push_back(Vector *v, void *elem) {
    // add element to end of the vector
    assert(v != NULL);
    assert(elem != NULL);

    if (v->size == v->capacity) {
        v->data = realloc(v->data, v->capacity + 5);
        v->capacity += 5;
    }
    
    v->data[v->size] = elem;
    v->size++;
}

void *pop_back(Vector *v) {
    // delete last element in vector
    assert(v != NULL);
    
    if (v->size > 0) {
        v->size--;
        void *value = v->data[v->size]; 
        return value;

    }
    return NULL;
}

void assign(Vector *v, void *new, const unsigned int pos) {
    assert(v != NULL);

    if (pos > v->size) {
        fprintf(stderr, "position overflow.\n");
        return;
    }
    int actual_pos = pos - 1;
    v->data[actual_pos] = new;
} 

void resize(Vector *v, size_t resize) {
    if (resize < v->size) {
        fprintf(stderr, "can't shrink vector.\n");
        return;
    }

    v->data = realloc(v->data, resize);

    v->size = resize;
    if (resize > v->capacity) {
        v->capacity = resize;
    }

}


void *at(Vector *v, const unsigned int pos) {
    assert(v != NULL);

    if (pos > v->size) {
        fprintf(stderr, "position overflow.\n");
        return NULL;
    }
    int actual_pos = pos - 1;
    return v->data[actual_pos];
}




void vremove(Vector *v, const unsigned int pos) {
    assert(v != NULL);

    if (pos >= v->size) {
        fprintf(stderr, "position overflow.\n");
        return;
    }

    void **old = v->data;
    
    
    int actual_pos = pos - 1;
    
    if (pos == 1) {
        v->data[actual_pos] = NULL;
        v->size--;
    } else if (pos < v->size) {
        v->data[actual_pos] = NULL;
    
        memcpy(v->data[actual_pos], v->data[pos], v->size - actual_pos);
        v->size--;

    } else {
        v->data[actual_pos] = NULL;
        v->size--;
    }
}

void clean(Vector *v) {
    free(v->data);
    v->capacity = 0;
    v->size = 0;
    free(v);
}


int capacity(Vector *v) {
    return v->capacity;
}

int size(Vector *v) {
    return v->size;
}

int empty(Vector *v) {
    return v->size == 0 ? true : false;
}
