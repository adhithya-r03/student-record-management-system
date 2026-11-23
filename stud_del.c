#include"student.h"
void delete_roll(int roll){

    stu *prev,*del=headptr;
    while(del){
        if(del->rollno == roll){
            if(del == headptr){
                headptr = del->next;
                free(del);
                del = headptr;
            }
            else{
                prev->next = del->next;
                free(del);
            }
            return;   
        }
        prev = del;
        del = del -> next;
    }
    printf("roll no. not found\n");
}

int my_strcmp(char *p,char *q){

    while(*p){
        if(*p!=*q){
            break;
        }
        p++;
        q++;
    }
    if(*p==*q)
        return 0;
    else if(*p>*q)
        return -1;
    else
        return 1;
}
void delete_name(){
    char s[30];
    int c=0,a;
    printf("Enter name to delete:");
    scanf("%s",s);
    stu *del=headptr,*prev;
    stu *ptr = headptr;
    while(ptr){
        if(my_strcmp(ptr->name,s)==0){
            c++;
        }
        ptr = ptr->next;
    }
    if(c>1){
        del = headptr;
        printf("More records found:\n");
        while(del){
            if(my_strcmp(del->name,s)==0){
                printf("%d %s %.2f\n",del->rollno,del->name,del->percentage);
            }
            del = del->next;
        }
        printf("Enter Roll no to delete:");
        scanf("%d",&a);
        delete_roll(a);
    }
    else if(c==1){
        del=headptr;
    while(del){
        if(my_strcmp(del->name,s)==0){
            if(del == headptr){
                headptr = del->next;
                free(del);
                del = headptr;
            }
            else{
                prev->next = del->next;
                free(del);
            }
            return;   
        }
        prev = del;
        del = del -> next;
    }
    }
    else{
        printf("No name found\n");
    }
}

        
void delete_rec(){
    char op;
    char s[20];
    int roll;
    printf("R/r : Enter roll number to delete\nN/n : Enter name to delete\n");
    scanf(" %c",&op);
    switch(op){
        case ('r'):
        case ('R'):printf("Enter roll no to delete:");scanf("%d",&roll);delete_roll(roll);break;
        case ('n'):
        case ('N'):delete_name();break;
        default:printf("invalid option\n");
    }
}

void delete_all(){
    if(headptr==0){
        printf("no memory used\n");
    }
    stu *del = headptr;
    while(del){
        headptr = del->next;
        free(del);
        del = headptr;
    } 
    printf("Deleted all allocated memory\n");
}