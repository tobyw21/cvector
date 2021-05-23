#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

int main(void) {
    Vector v = ivector(int_);

    for (int i = 0; i < 5; i++) {
        int k = i + 1;
        push_back(v, &k);
    }

    pop_back(v);

    for (int j = 0; j < 5; j++) {
        print_vec(v, j, int_);
    }

    clean(v);

    return 0;
}