#include"student.h"

void add_new(){

    stu *new = malloc(sizeof(stu));
    stu *ptr = headptr,*prev;
    int r;

    r =1;
    int flag =0;
    while(r){
        flag = 0;
        ptr = headptr;
       while(ptr){
        if(ptr->rollno==r){
            flag = 1;
            break;
        }
        ptr = ptr->next;
       }
       if(flag ==0){
        break;
       }
       r++;
    }
    new->rollno = r;
    printf("Enter students name:");
    scanf(" %[^\n]",new->name);
    while(1){
    printf("Enter student Percentage:");
    scanf("%f",&new->percentage);
    if(new->percentage >= 0 && new->percentage <=100){
        break;
    }
    printf("Percentage can only be between 0 to 100\n");
    }
    new->next =0;

    if(headptr==0){
        headptr=new;
    }
    else{
        ptr = headptr;
        while(ptr->next){
            ptr=ptr->next;
        }
        ptr->next = new;
    }
}