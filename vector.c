#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "vector.h"

#define typeof sizeof(typeof)

struct Vector
{
    unsigned int size;
    unsigned int capacity;
    unsigned int typesize;
    void **data;
    // if pushing structs, need to implement Clone and Drop
    void (*clone)(void *dest, void *src);
    void (*drop)(void *elem);
};

Vector *vector(size_t typesize)
{
    // initialize a vector container
    Vector *v = malloc(sizeof(struct Vector));

    v->capacity = INIT_VEC_SIZE;
    v->size = 0;
    v->data = malloc(sizeof(void *) * INIT_VEC_SIZE);
    v->typesize = typesize;
    v->clone = NULL;
    v->drop = NULL;

    return v;
}

void impl(Vector *v, void (*clone)(void *dest, void *src), void (*drop)(void *elem))
{
    // impl clone, drop for vector
    v->clone = clone;
    v->drop = drop;
}

void push_back(Vector *v, void *elem)
{
    // add element to end of the vector
    assert(v != NULL);
    assert(elem != NULL);

    if (v->size == v->capacity)
    {
        v->data = realloc(v->data, v->capacity + 5);
        v->capacity += 5;
    }
    v->data[v->size] = malloc(v->typesize);
    if (v->clone == NULL)
    {
        memcpy(v->data[v->size], elem, v->typesize);
    }
    else
    {
        v->clone(v->data[v->size], elem);
    }

    v->size++;
}

void *pop_back(Vector *v)
{
    // delete last element in vector
    assert(v != NULL);

    if (v->size > 0)
    {
        v->size--;
        void *value = v->data[v->size];
        return value;
    }
    return NULL;
}

void assign(Vector *v, void *new, const unsigned int pos)
{
    assert(v != NULL);

    if (pos > v->size)
    {
        fprintf(stderr, "position overflow.\n");
        return;
    }

    if (v->data[pos] == NULL)
    {
        fprintf(stderr, "assign to uninitialised position.\n");
        return;
    }
    // v->data[actual_pos] = new;
    memcpy(v->data[pos], new, v->typesize);
}

void resize(Vector *v, size_t resize)
{
    if (resize < v->size)
    {
        fprintf(stderr, "can't shrink vector.\n");
        return;
    }

    v->data = realloc(v->data, resize);

    v->size = resize;
    if (resize > v->capacity)
    {
        v->capacity = resize;
    }
}

void *at(Vector *v, const unsigned int pos)
{
    assert(v != NULL);

    if (pos > v->size)
    {
        fprintf(stderr, "position overflow.\n");
        return NULL;
    }
    return v->data[pos];
}

void delete(Vector *v, const unsigned int pos)
{
    assert(v != NULL);

    if (pos >= v->size)
    {
        fprintf(stderr, "position overflow.\n");
        return;
    }

    if (v->drop)
    {
        v->drop(v->data[pos]);
    }
    else
    {
        free(v->data[pos]);
    }

    if (pos < v->size)
    {
        memmove(&v->data[pos], &v->data[pos + 1], (v->size - pos) * v->typesize);
    }
    v->size--;
}

void clean(Vector *v)
{
    for (int i = 0; i < v->size; i++)
    {
        if (v->drop)
        {
            v->drop(v->data[i]);
        }
        else
        {
            free(v->data[i]);
        }
    }
    free(v->data);
    v->capacity = 0;
    v->size = 0;
    v->clone = NULL;
    v->drop = NULL;
    free(v);
}

int capacity(Vector *v)
{
    return v->capacity;
}

int size(Vector *v)
{
    return v->size;
}

int empty(Vector *v)
{
    return v->size == 0 ? true : false;
}

void **data(Vector *v)
{
    return v->data;
}
