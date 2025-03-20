#include <stdio.h>

int main() {
    int* ip;
    *ip = 2;  // Bug: using uninitialized pointer
    printf("%%x\n", *ip);
    return 0;
}
