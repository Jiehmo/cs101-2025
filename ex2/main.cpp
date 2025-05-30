#include <stdio.h>
#include <string.h>

// 定義 employee_t 結構
typedef struct employee {
    int id;
    int age;
    double salary;
    char name[50];
} employee_t;

// 顯示單一員工資訊
void emp_info(employee_t emp) {
    printf("employee id = %d\n", emp.id);
    printf("employee name = %s\n", emp.name);
    printf("employee age = %d\n", emp.age);
    printf("employee salary = %lf\n", emp.salary);
}

// 計算員工平均年齡
int emp_average_age(employee_t emp[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += emp[i].age;
    }
    return (n > 0) ? (sum / n) : 0;
}

// 將員工資料寫入二進制檔案
void emp_writefile(employee_t emp[], int n) {
    FILE* fp = fopen("employee.bin", "wb+");
    if (fp == NULL) {
        printf("無法開啟檔案進行寫入\n");
        return;
    }
    
    for (int i = 0; i < n; i++) {
        fwrite(&emp[i], sizeof(employee_t), 1, fp);
    }
    
    fclose(fp);
    return;
}

// 從二進制檔案讀取員工資料
void emp_readfile(employee_t emp[], int n) {
    FILE* fp = fopen("employee.bin", "rb");
    if (fp == NULL) {
        printf("無法開啟檔案進行讀取\n");
        return;
    }
    
    int i = 0;
    employee_t tmp;
    
    while (fread(&tmp, sizeof(employee_t), 1, fp) && i < n) {
        emp[i].id = tmp.id;
        emp[i].age = tmp.age;
        emp[i].salary = tmp.salary;
        strcpy(emp[i].name, tmp.name);
        
        printf("[%d] %d %s\n", i, emp[i].id, emp[i].name);
        i++;
    }
    
    fclose(fp);
    return;
}

int main() {
    // 建立三位員工的資料
    employee_t emp[3];
    
    // 第一位員工
    emp[0].id = 1;
    emp[0].age = 20;
    emp[0].salary = 30000.0;
    strcpy(emp[0].name, "IU");
    
    // 第二位員工
    emp[1].id = 2;
    emp[1].age = 26;
    emp[1].salary = 36000.0;
    strcpy(emp[1].name, "taylor");
    
    // 第三位員工
    emp[2].id = 3;
    emp[2].age = 31;
    emp[2].salary = 90000.0;
    strcpy(emp[2].name, "swift");
    
    // 寫入檔案
    emp_writefile(emp, 3);
    
    // 準備讀取檔案的陣列
    employee_t read_emp[10];
    
    // 讀取檔案
    emp_readfile(read_emp, 10);
    
    // 顯示讀取出來的員工資料
    for (int i = 0; i < 3; i++) {
        emp_info(read_emp[i]);
    }
    
    return 0;
}

