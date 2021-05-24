typedef enum {
    char_,
    int_,
    float_,
    double_
} Type;

struct Vector {
    int size;
    int capacity;
    int elem_size;
    void *data;
};
typedef struct Vector *Vector;

/* struct iterator {
    int elem_size;
    void *ptr;
};
typedef struct iterator *Iterator; */

// initialize a vector container
Vector ivector(Type t);

// initialize a vector with given capacity
Vector nvector(Type t, int capa_exp);

 // add element to end of the vector
Vector push_back(Vector v, void *elem);

 // delete last element in vector
Vector pop_back(Vector v);

// assign new value to exist offset
Vector assign(Vector v, void *new_val, int n);

//resize the vector by given size
Vector vec_resize(Vector v, size_t resize);

// because C doesn't have destructor so have to free the container after use
void clean(Vector v);

// vector exists as an ADT therefore need a function to print it 
void print_vec(Vector v, int offset, Type t);

// return the max size vector can contain
int max_size(Vector v);

// return the capacity of the vector
int capacity(Vector v);

// return size of vector
int size(Vector v);

// return if vector is empty
int empty(Vector v);

// shrink vector capacity to size and destory all exceeding elements
Vector shrink_to_fit(Vector v);

// return element at offset n
void *at(Vector v, int offset);

// return the element in the front of the vector
void *front(Vector v);

// return the element in the back of the vector
void *back(Vector v);

// return the pointer points to the data segment of the ADT
void **data(Vector v);