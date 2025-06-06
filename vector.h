typedef struct Vector Vector;


#define INIT_VEC_SIZE 8

#define deref(ptr, underlying_type) (*(underlying_type *)ptr)


// initialize a vector container
Vector *vector();

 // add element to end of the vector
void push_back(Vector *v, void *elem);

 // delete last element in vector
void *pop_back(Vector *v);

// assign new value to exist offset
void assign(Vector *v, void *new, const unsigned int pos);

//resize the vector by given size
void resize(Vector *v, size_t resize);

void *at(Vector *v, const unsigned int pos);

// because C doesn't have destructor so have to free the container after use
void clean(Vector *v);

// return the capacity of the vector
int capacity(Vector *v);

// return size of vector
int size(Vector *v);

// return if vector is empty
int empty(Vector *v);
