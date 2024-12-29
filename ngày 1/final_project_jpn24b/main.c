#include <stdio.h>
#include "function.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
int choice;
int n=0;
struct Student student[50];
do{
	printf("-----STUDENT MANAGEMENT-------\n");
	printf("1.ADD A NEW STUDENT\n");
	printf("2.SHOW ALL STUDENT\n");
	printf("3.SHOW ALL STUDENT ROWS,COLW\n");
	printf("4.SEARCH A STUDENT\n");
	printf("5.EDIT STUDENT INFORMATION\n");
	printf("6.DELETE STUDENT\n");
	printf("7.EXIT\n");
	printf("PLEASE ENTER YOUR CHOICES : ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
		if (n < 20) {
                    addStudent(&student[n]); 
                    n++;
                } else {
                    printf("STUDENT FULL\n");
                }
                break;
        case 2:
        	 if (n == 0) {
                    printf("Danh sach sinh vien trong!\n");
                } else {
                    Studentlish(student, n); 
                }
                break;
        	
        case 3 : 
          if (n == 0) {
                  printf("EMPTY LISH ! PLEASE ADD STUDENT\n");
              } else {
                   listStudent(student,n); 
                }
            break;
				      
		
		
	}
	
}while(choice !=6);

	
	
	
	return 0;
}
