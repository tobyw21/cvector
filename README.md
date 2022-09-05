# cvector
C++ basic vector implemented in C 

Vector in C++
- Dynamic Array
- Automatically arrange memory
```Cpp
    vector<int> v;

    for (int i = 0; i < 5; i++) {
        v.push_back(i + 1);
    }

    for (int j : v) {
        cout << "vector<int> [" << j - 1 << "]" << " = " << j << endl;
    }

    v.clear();

    return 0;
```

        +--------+
        |        |
        |  size  |
        |        |
        +--------+
        |        |
        |capacity|
        |        |
        +--------+ <-- Start Pointer
        |        |
        | data   |
        |        |
        +--------+

Vector implemented in C

What's in the struct
- void pointer array - any type reference
- size
- capacity

Note that void pointer can't visit elements by indexing, here used pointer
arithmetic (unsafe)

