#include <stdio.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        // 基本情況：只有一個盤子時，直接從起始柱移到目標柱
        printf("\n移動盤子 1 從柱子 %c 到柱子 %c", from_rod, to_rod);
        return;
    }
    
    // 第1步：將n-1個盤子從起始柱移到輔助柱
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    
    // 第2步：將第n個盤子從起始柱移到目標柱
    printf("\n移動盤子 %d 從柱子 %c 到柱子 %c", n, from_rod, to_rod);
    
    // 第3步：將n-1個盤子從輔助柱移到目標柱
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main() {
    int n = 3;  // 盤子數量
    towerOfHanoi(n, 'A', 'B', 'C');  // A、B和C是三根柱子的名稱
    printf("\n\n總共需要移動次數：%d\n", (1<<n)-1);  // 2^n - 1
    return 0;
}
