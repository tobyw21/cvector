#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "vector.h"

typedef struct person
{
    char *name;
    int age;
} Person;

typedef struct car
{
    int year;
    char *brand;
    Person driver;
} Car;

void test1()
{
    Vector *v = vector(sizeof(int));

    int i, j, k;
    i = 1;
    j = 2;
    k = 3;

    push_back(v, &i);
    push_back(v, &j);
    push_back(v, &k);

    void *r1, *r2, *r3, *r4;

    r4 = at(v, 1);

    printf("at 1 = %d\n", deref(r4, int));
    r1 = pop_back(v);
    r2 = pop_back(v);
    r3 = pop_back(v);

    printf("%d %d %d\n", deref(r1, int), deref(r2, int), deref(r3, int));
    free(r1);
    free(r2);
    free(r3);

    clean(v);
}

void test2()
{

    Vector *v = vector(sizeof(Person));
    Person p1, p2;
    p1.name = "Elton John";
    p1.age = 70;

    p2.name = "John Doe";
    p2.age = 19;

    push_back(v, &p1);
    push_back(v, &p2);

    void *r5, *r6, *r7;
    r5 = at(v, 1);
    printf("p1 name=%s, age=%d\n", deref(r5, Person).name, deref(r5, Person).age);

    Person p3;

    p3.name = "John Smith";
    p3.age = 43;

    assign(v, &p3, 1);
    r6 = at(v, 1);
    printf("p2 name=%s, age=%d\n", deref(r6, Person).name, deref(r6, Person).age);

    push_back(v, &p2);
    printf("%d\n", size(v));
    delete(v, 1);

    printf("%d\n", size(v));

    r7 = at(v, 1);
    printf("p2 name=%s, age=%d\n", deref(r7, Person).name, deref(r7, Person).age);
    clean(v);
}

char *strdup(char *s)
{
    int l = strlen(s) + 1;
    char *d = (char *)malloc(sizeof(char) * l);
    strcpy(d, s);
    return d;
}

void clone(void *dest, void *src)
{
    Car *s = (Car *)src;
    Car *d = (Car *)dest;
    d->brand = strdup(s->brand);
    d->year = s->year;

    d->driver.name = strdup(s->driver.name);
}

void drop(void *elem)
{
    Car *c = (Car *)elem;
    free(c->driver.name);
    free(c->brand);
    free(c);
}

void test3()
{
    Vector *v = vector(sizeof(Car));
    impl(v, clone, drop);

    Person p;
    p.age = 70;
    p.name = (char *)malloc(10);
    strcpy(p.name, "Ethan");

    Car *c = (Car *)malloc(sizeof(Car));
    c->brand = (char *)malloc(10);
    strcpy(c->brand, "bmw");

    c->driver = p;
    c->year = 1970;

    push_back(v, c);

    void *r = at(v, 0);

    printf("%s owner is %s\n", deref(r, Car).brand, deref(r, Car).driver.name);
    free(p.name);
    free(c->brand);
    free(c);

    clean(v);
}

int main(void)
{

    test1();
    test2();
    test3();
    return 0;
}