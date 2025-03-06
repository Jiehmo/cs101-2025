#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fp;
    int a[] = {0, 1, 2};
    char b[] = "ABC";
    float c[] = {1.1, 1.2, 1.3};

    // 打開文件進行讀寫
    fp = fopen("a.bin", "wb+");
    if (fp == NULL) {
        printf("無法打開文件\n");
        return 1;
    }

    // 將數據寫入文件
    fwrite(a, sizeof(int), 3, fp);
    fwrite(b, sizeof(char), 3, fp);
    fwrite(c, sizeof(float), 3, fp);

    // 重置文件指針到文件開頭
    rewind(fp);

    // 讀取數據
    int ra[3];
    char rb[3];
    float rc[3];
    fread(ra, sizeof(int), 3, fp);
    fread(rb, sizeof(char), 3, fp);
    fread(rc, sizeof(float), 3, fp);

    // 關閉文件
    fclose(fp);

    // 輸出整數陣列
    for (int i = 0; i < 3; i++) {
        printf("%d ", ra[i]);
    }
    printf("\n");

    // 輸出字元陣列
    for (int i = 0; i < 3; i++) {
        printf("%c ", rb[i]);
    }
    printf("\n");

    // 輸出浮點數陣列
    for (int i = 0; i < 3; i++) {
        printf("%.5f ", rc[i]);
    }
    printf("\n");

    return 0;
}
