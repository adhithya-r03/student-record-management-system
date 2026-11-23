#include"student.h"

void print_rec(){
    if(headptr==0){
        printf("No records\n");
        return;
    }
    stu *ptr=headptr;
    printf("------------------------------------------\n");
    printf("Rollno name percentage\n");
    printf("------------------------------------------\n");
    while(ptr){
        printf("%d %s %.2f\n",ptr->rollno,ptr->name,ptr->percentage);
        ptr=ptr->next;
    }
    printf("------------------------------------------\n");
}

void print_rec_roll(int roll){
    if(headptr==0){
        printf("No records\n");
        return;
    }
    stu *ptr=headptr;
    while(ptr){
        if(ptr->rollno == roll){
            printf("------------------------------------------\n");
            printf("Rollno name percentage\n");
            printf("------------------------------------------\n");
            printf("%d %s %.2f\n",ptr->rollno,ptr->name,ptr->percentage);
            printf("------------------------------------------\n");
            return;
        }
        ptr=ptr->next;
    }
}