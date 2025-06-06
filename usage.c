#include <stdio.h>

#include "vector.h"

int main(void) {
    Vector *v = vector();


    int i, j, k;
    i = 1;
    j = 2;
    k = 3;

    push_back(v, &i);
    push_back(v, &j);
    push_back(v, &k);

    void *r1, *r2, *r3;

    r1 = pop_back(v);
    r2 = pop_back(v);
    r3 = pop_back(v);

    printf("%d %d %d\n", deref(r1, int), deref(r2, int), deref(r3, int));

    
    
    typedef struct person {
        char *name;
        int age;
    } Person;
    
    Person p1, p2;
    p1.name = "Elton John";
    p1.age = 70;
    
    p2.name = "John Doe";
    p2.age = 19;
    
    push_back(v, &p1);
    push_back(v, &p2);
    
    void *r5, *r6, *r7;
    r5 = at(v, 1);
    printf("p1 name=%s, age=%d\n", deref(r5, Person));
    
    Person p3;

    p3.name = "John Smith";
    p3.age = 43;

    assign(v, &p3, 2);
    r6 = at(v, 2);
    printf("p2 name=%s, age=%d\n", deref(r6, Person));

    push_back(v, &p2);
    printf("%d\n", size(v));
    vremove(v, 2);

    printf("%d\n", size(v));

    r7 = at(v, 2);
    printf("p2 name=%s, age=%d\n", deref(r7, Person));
    
    clean(v);
    return 0;
}