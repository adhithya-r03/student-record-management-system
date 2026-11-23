#include"student.h"

void save_rec(){
    if(headptr == 0){
        printf("No records to save\n");
        return;
    }
    FILE *fp= fopen("student.dat","w");
    stu *ptr = headptr;
    while(ptr){
        fprintf(fp,"%d %s %.2f\n",ptr->rollno,ptr->name,ptr->percentage);
        ptr = ptr->next;
    }
    printf("Details saved\n");
}

void read_file(){
    stu *last;
    FILE *fp = fopen("student.dat","r");
    if(fp==0){
        printf("No save file found\n");
        return;
    }
    while(1){
        stu *new = malloc(sizeof(stu));
        if(fscanf(fp,"%d%s%f",&new->rollno,new->name,&new->percentage)==-1){
            free(new);
            break;
        }
        new->next=0;
        if(headptr==0){
            headptr = new;
        }
        else{
            last = headptr;
            while(last->next)
                last = last->next;
            last->next = new;
        }    
    }
    printf("Saved details loaded\n");
}

void save_exit(){
    save_rec();
    delete_all();
    exit(0);
}

void no_save(){
    printf("Exiting without saving....\n");
    delete_all();
    exit(0);
}

void exit_rec(){

    char op;
    printf("S/s : Save and exit\nE/e : Exit without saving\noption:");
    scanf(" %c",&op);
    switch(op){
        case ('S'):
        case ('s'):save_exit();break;
        case ('E'):
        case ('e'):no_save();break;
        default:printf("Not a valid option\n");
    }
}