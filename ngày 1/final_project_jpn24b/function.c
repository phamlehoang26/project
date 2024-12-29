#include "function.h"
#include<stdio.h>
#include<string.h>
 void addStudent(struct Student* student) {
    getchar();
    printf("ID : ");
    fgets(student->studentId, sizeof(student->studentId), stdin);
    student->studentId[strcspn(student->studentId, "\n")] = '\0';
    //ten
    printf("NAME STUDENT: ");
    fgets(student->name, sizeof(student->name), stdin);
    student->name[strcspn(student->name, "\n")] = '\0';
    //tuoi
    printf("DATE : (dd mm yyyy): ");
    scanf("%d %d %d", &student->dateOfBirth.day, &student->dateOfBirth.month, &student->dateOfBirth.year);
    //gioi tinh
    printf("GENDER ( 1.MAN, 2.WOMEN): ");
    scanf("%d", (int*)&student->gender);
    // email
    getchar(); 
    printf("EMAIL : ");
    fgets(student->email, sizeof(student->email), stdin);
    student->email[strcspn(student->email, "\n")] = '\0';
    // so dien thoai
    printf("PHONE : ");
    fgets(student->phone, sizeof(student->phone), stdin);
    student->phone[strcspn(student->phone, "\n")] = '\0';
    // thanh cong
    printf("MORE SUCCESSFUL STUDENTS\n");
    
    
}

void displayStudent(const struct Student* student) {
    printf("\nID : %s\n", student->studentId);
    printf("NAME : %s\n", student->name);
    printf("DATE : %02d/%02d/%04d\n", 
         student->dateOfBirth.day, student->dateOfBirth.month, student->dateOfBirth.year);
    printf("GENDER : %d\n", student->gender);
    printf("EMAIL : %s\n", student->email);
    printf("PHONE : %s\n", student->phone);
}
void Studentlish(const struct Student student[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nSinh vien thu %d:\n", i + 1);
        displayStudent(&student[i]);
    }
}
void printStudentRows(const struct Student* student);
   

void saveStudentsToFile(struct Student student[], int n) {
    FILE *ptr = fopen("student.bin", "wb"); 
    if (ptr == NULL) {
        printf("Loi: Khong mo duoc tep ");
        return;
    }
    fwrite(student,50,6,ptr);
    printf("du lieu da duoc luu");
    fclose(ptr);
}
void listStudent(const struct Student student[], int n) {//const là biêsn hàngw chi de doc
    printf("\n%-70s\n", "================================= DANH SACH SINH VIEN ================================");
    printf("| %-10s | %-20s |  %-10s | %-6s | %-30s | %-15s |\n", 
           "ID", "NAME", "DATE", "GENDER", "EMAIL", "PHONE");
    printf("---------------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("| %-10s | %-20s | %02d/%02d/%4d | %-6s | %-30s | %-15s |\n",
               student[i].studentId,
               student[i].name,
               student[i].dateOfBirth.day,
               student[i].dateOfBirth.month,
               student[i].dateOfBirth.year,
               student[i].gender ? "MAN" : "WOMEN",
               student[i].email,
               student[i].phone);
    }

    printf("%-70s\n", "=======================================================================================");
}



















