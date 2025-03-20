#include <stdio.h>

int main() {
    int* ip;
    ip = 2;  // Bug: direct assignment of int to pointer
    printf("%%x\n", ip);
    printf("%%x\n", *ip);  // Bug: dereferencing an invalid pointer
    return 0;
}
