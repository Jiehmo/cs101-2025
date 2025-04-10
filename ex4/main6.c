#include <stdio.h>

// 遞迴實現階乘函數
int factorial(int n) {
    if (n == 1) return 1;  // 中止條件
    return n * factorial(n - 1);  // 遞迴調用
}

int main() {
    int n = 5;
    int m = factorial(n);
    printf("階乘 %d = %d\n", n, m);
    return 0;
}
