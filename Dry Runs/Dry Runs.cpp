#include <iostream>
#include <cstddef>

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    for (int i = 0; i < len; i++) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void* x) {
    show_bytes((byte_pointer)&x, sizeof(void*));
}

int main() {
    int i = 12345;
    float f = 12345.0f;
    void* p = &i;

    std::cout << "int: ";
    show_int(i);

    std::cout << "float: ";
    show_float(f);

    std::cout << "pointer: ";
    show_pointer(p);

    return 0;
}