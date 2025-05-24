#include <stdio.h>
#include <string.h>

#define MAX 100
#define SUBJECTS 3

typedef struct {
    char name[13];
    float scores[SUBJECTS];
    float total;
} Student;

Student students[MAX];
int n = 0;

// 函数声明
void inputData();
void outputData();
void calculateTotal();
void findHighestEachSubject();
void sortByTotalScore();
void filterByThreshold();

int main() {
    int choice;
    do {
        printf("\n===== 学生成绩管理系统 =====\n");
        printf("1. 输入学生成绩\n");
        printf("2. 输出学生成绩\n");
        printf("3. 计算总分\n");
        printf("4. 查找单项最高分\n");
        printf("5. 按总分排序\n");
        printf("6. 达标筛选\n");
        printf("0. 退出系统\n");
        printf("请选择功能（0-6）：");
        scanf("%d", &choice);
        switch (choice) {
            case 1: inputData(); break;
            case 2: outputData(); break;
            case 3: calculateTotal(); break;
            case 4: findHighestEachSubject(); break;
            case 5: sortByTotalScore(); break;
            case 6: filterByThreshold(); break;
            case 0: printf("退出系统。\n"); break;
            default: printf("无效选择，请重新输入。\n");
        }
    } while (choice != 0);
    return 0;
}

void inputData() {
    printf("请输入学生人数：");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("请输入第 %d 位学生的姓名：", i + 1);
        scanf("%s", students[i].name);
        for (int j = 0; j < SUBJECTS; j++) {
            printf("  输入项目 %d 成绩：", j + 1);
            scanf("%f", &students[i].scores[j]);
        }
    }
}

void outputData() {
    printf("\n%-10s  项目1  项目2  项目3\n", "姓名");
    for (int i = 0; i < n; i++) {
        printf("%-10s", students[i].name);
        for (int j = 0; j < SUBJECTS; j++) {
            printf("  %.2f", students[i].scores[j]);
        }
        printf("\n");
    }
}

void calculateTotal() {
    printf("\n%-10s  总分\n", "姓名");
    for (int i = 0; i < n; i++) {
        float sum = 0;
        for (int j = 0; j < SUBJECTS; j++) {
            sum += students[i].scores[j];
        }
        students[i].total = sum;
        printf("%-10s  %.2f\n", students[i].name, students[i].total);
    }
}

void findHighestEachSubject() {
    for (int j = 0; j < SUBJECTS; j++) {
        int maxIndex = 0;
        for (int i = 1; i < n; i++) {
            if (students[i].scores[j] > students[maxIndex].scores[j]) {
                maxIndex = i;
            }
        }
        printf("项目 %d 最高分：%s（%.2f）\n", j + 1, students[maxIndex].name, students[maxIndex].scores[j]);
    }
}

void sortByTotalScore() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].total < students[j].total) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("\n按总分排序结果：\n");
    printf("%-10s  总分\n", "姓名");
    for (int i = 0; i < n; i++) {
        printf("%-10s  %.2f\n", students[i].name, students[i].total);
    }
}

void filterByThreshold() {
    float threshold;
    printf("请输入筛选的总分阈值：");
    scanf("%f", &threshold);
    printf("\n总分超过 %.2f 的学生：\n", threshold);
    printf("%-10s  总分\n", "姓名");
    for (int i = 0; i < n; i++) {
        if (students[i].total >= threshold) {
            printf("%-10s  %.2f\n", students[i].name, students[i].total);
        }
    }
}
