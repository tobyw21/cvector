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

struct iterator {
    int elem_size;
    void *ptr;
};
typedef struct iterator *Iterator;

// initialize a vector container
Vector ivector(Type t);

// initialize a vector with given capacity
Vector nvector(Type t, int capa_exp);


 // add element to end of the vector
Vector push_back(Vector v, void *elem);

 // delete last element in vector
Vector pop_back(Vector v);

// because C doesn't have destructor so have to free the container after use
void clean(Vector v);

// vector exists as an ADT therefore need a function to print it 
void print_vec(Vector v, int offset, Type t);

void printsize(Vector v);