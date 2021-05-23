#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <limits.h>

#include "vector.h"

#define STD_VEC_SIZE 8

Vector ivector(Type t) {
    // initialize a vector container
    Vector v = malloc(sizeof(struct Vector));

    switch (t) {
        case char_:
            v->capacity = STD_VEC_SIZE;
            v->elem_size = sizeof(char);
            v->size = 0;
            v->data = malloc(sizeof(char) * v->capacity);
            break;

        case int_:
            v->capacity = STD_VEC_SIZE;
            v->elem_size = sizeof(int);
            v->size = 0;
            v->data = malloc(sizeof(int) * v->capacity);
            break;

        case float_:
            v->capacity = STD_VEC_SIZE;
            v->elem_size = sizeof(float);
            v->size = 0;
            v->data = malloc(sizeof(float) * v->capacity);
            break;

        case double_:
            v->capacity = STD_VEC_SIZE;
            v->elem_size = sizeof(double);
            v->size = 0;
            v->data = malloc(sizeof(double) * v->capacity);
            break;

        default:
            fprintf(stderr, "No data type specified\n");
            return NULL;
    }

    return v;
}

Vector nvector(Type t, int capa_exp) {
    // initialize a vector with given capacity
    Vector v = malloc(sizeof(struct Vector));

    switch (t) {
        case char_:
            v->capacity = capa_exp;
            v->elem_size = sizeof(char);
            v->size = 0;
            v->data = malloc(sizeof(char) * v->capacity);
            break;

        case int_:
            v->capacity = capa_exp;
            v->elem_size = sizeof(int);
            v->size = 0;
            v->data = malloc(sizeof(int) * v->capacity);
            break;

        case float_:
            v->capacity = capa_exp;
            v->elem_size = sizeof(float);
            v->size = 0;
            v->data = malloc(sizeof(float) * v->capacity);
            break;

        case double_:
            v->capacity = capa_exp;
            v->elem_size = sizeof(double);
            v->size = 0;
            v->data = malloc(sizeof(double) * v->capacity);
            break;

        default:
            fprintf(stderr, "No data type specified\n");
            return NULL;
    }

    return v;
}


Vector push_back(Vector v, void *elem) {
    // add element to end of the vector
    assert(v != NULL);
    assert(elem != NULL);

    if (v->size > v->capacity) {
        v->data = realloc(v->data, v->size * v->elem_size);
    }

    void *offset = v->data + (v->size * v->elem_size);
    memcpy(offset, elem, v->elem_size);
    v->size++;

    return v;
}

Vector pop_back(Vector v) {
    // delete last element in vector
    assert(v != NULL);
    
    void *offset = v->data + ((v->size - 1) * v->elem_size);
    offset = NULL;
    v->size--;

    return v;
}

Vector vec_resize(Vector v, size_t resize) {
    if (resize < v->size) {
        fprintf(stderr, "Unable to Resize\n");
        return NULL;
    }

    void *old = v->data;
    v->data = realloc(v->data, resize);
    memcpy(v->data, old, v->elem_size);
    v->size = resize;
    if (resize > v->capacity) {
        v->capacity = resize;
    }

    return v;
}

void clean(Vector v) {
    free(v->data);
    v->capacity = 0;
    v->elem_size = 0;
    v->size = 0;
    free(v);
}

void print_vec(Vector v, int offset, Type t) {

    if (offset < v->size) {
        void *val = v->data + (offset * v->elem_size);
        
        switch (t) {
            case int_:
                printf("vector<int> [%d] = %d\n", offset, *((int *)val));
                break;

            case char_:
                printf("vector<char> [%d] = %c\n", offset, *((char *)val));
                break;

            case double_:
                printf("vector<double> [%d] = %lf\n", offset, *((double *)val));
                break;

            case float_:
                printf("vector<float> [%d] = %f\n", offset, *((float *)val));
                break;

            default:
                fprintf(stderr, "Invalid Vector Type\n");
        }

    } else {
        printf("Offset [%d] Exceed Vector Size Range\n", offset);
        
    }
    
}

void printsize(Vector v) {
    printf("%d\n", v->size);
}