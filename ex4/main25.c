#include <stdio.h>

// 遞迴生成單行乘法表
int multi(int i, int j) {
    if (j == 1) {
        printf("%d*%d=%d\n", i, j, i*j);
        return 0;
    } else {
        multi(i, j-1);  // 先遞迴處理較小的值
        printf("%d*%d=%d\n", i, j, i*j);
    }
}

// 遞迴生成完整九九乘法表
void complete_table(int i, int j) {
    if (i > 9) return;  // 所有行都處理完畢
    
    multi(i, j);  // 生成當前行
    
    if (j == 9) {
        // 轉到下一行
        complete_table(i+1, 9);
    }
}

int main() {
    // 單獨列印1的乘法表（1×1到1×9）
    printf("1的乘法表：\n");
    multi(1, 9);
    
    printf("\n完整九九乘法表：\n");
    complete_table(1, 9);
    
    return 0;
}
