#include<stdio.h>
struct student{
    int id_no;
    char name[80];
};
//showing cgpa rank with name and id
void display(struct student list[80], int s){
    int i;
    printf("\n\nstu. id\t\tName\n");
    for (i = 0; i < s; i++){
        printf("%d\t\t%s\n", list[i].id_no, list[i].name);
    }
}
//using structure data record for student
void accept(struct student list[80], int s){
    int i;
    for (i = 0; i < s; i++){
        printf("\nEnter data for Record #%d", i + 1);
        printf("\nEnter id_no : ");
        scanf("%d", &list[i].id_no);
        fflush(stdin);
        printf("Enter name : ");
        gets(list[i].name);
    }
}
void main(){
    struct student data[80];
    int n;
    printf("welcome to cgpa ranking system:\n");
    printf("10 students records, please enter 10:");
    scanf("%d", &n);
    accept(data, n);
    //course grade for 10 students
    float course_grade_[10][10];
    //cgpa for 10 students
    float cgpa_student_[10];
    //input course grade
    int student,course;
    for(student=0; student<10; student++){
        printf("course grade for student no %d\n",student+1);
        for(course=0; course<10; course++){
            scanf("%f",&course_grade_[student][course]);
        }
    }
    //calculate cgpa
    for(student=0; student<10; student++){
        cgpa_student_[student]=0;
        for(course=0; course<10; course++){
            cgpa_student_[student]=cgpa_student_[student]+course_grade_[student][course]*3;
        }
        cgpa_student_[student]=cgpa_student_[student]/30;
    }
    //bubble sort
    int temp;
     for(student=0; student<10; student++){
        for(course=student+1; course<10; course++){
            if(cgpa_student_[student]>cgpa_student_[course]){
                temp=cgpa_student_[student];
                cgpa_student_[student]=cgpa_student_[course];
                cgpa_student_[course]=temp;
            }
        }
     }
     //print cgpa
    printf("\n\n");
    printf("Rank        CGPA\n");
    printf("==        ====\n");
    int counter;
    for(counter=0; counter<10; counter++){
    printf("%d        %.2f\n",counter+1, cgpa_student_[course]);
    }
    //using function for disply show
  display(data,n);
}

