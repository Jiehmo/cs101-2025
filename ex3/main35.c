#include <stdio.h>

int main() {
    char v = 'A';
    int* p = NULL;
    p = &v;  // Bug: assigning char* to int* (type mismatch)
    
    printf("Address of v: %%x\n", v);
    printf("Address stored in p: %%x\n", p);
    printf("Address of p: %%x\n", &p);
    printf("Value of *p: %%d\n", *p);  // Bug: dereferencing wrong type
    
    return 0;
}
