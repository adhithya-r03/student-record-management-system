#include"student.h"

void modify_roll(int roll){
    stu *ptr=headptr;
    while(ptr){
        if(ptr->rollno == roll){
            printf("Existing details:\n");
            print_rec_roll(roll);
            printf("Enter students name:");
            scanf(" %[^\n]",ptr->name);
            while(1){
            printf("Enter student Percentage:");
            scanf("%f",&ptr->percentage);
            if(ptr->percentage >= 0 && ptr->percentage <=100){
                break;
            }
            printf("Percentage can only be between 0 to 100\n");
            }
            printf("Modified details:\n");
            print_rec_roll(roll);
            return;
        }
        ptr = ptr->next;
    }
    printf("Roll no. not found\n");
}

void modify_name(){
    char s[30];
    int c=0,roll;
    stu *ptr = headptr;
    printf("Enter name to search:");
    scanf("%s",s);
    while(ptr){
        if(my_strcmp(ptr->name,s)==0){
            c++;
        }
        ptr = ptr->next;
    }
    if(c==0){
        printf("Name not found\n");
        return;
    }
    else if(c==1){
        ptr = headptr;
        while(ptr){
            if(my_strcmp(ptr->name,s)==0){
            printf("Existing details:\n");
            print_rec_roll(ptr->rollno);
            printf("Enter students name:");
            scanf(" %[^\n]",ptr->name);
            while(1){
            printf("Enter student Percentage:");
            scanf("%f",&ptr->percentage);
            if(ptr->percentage >= 0 && ptr->percentage <=100){
                break;
            }
            printf("Percentage can only be between 0 to 100\n");
            }
            printf("Modified details:\n");
            print_rec_roll(ptr->rollno);
            return;
            }
            ptr = ptr->next;
        }
    }
    else{
        ptr = headptr;
        printf("More records found:\n");
        while(ptr){
            if(my_strcmp(ptr->name,s)==0){
                printf("%d %s %.2f\n",ptr->rollno,ptr->name,ptr->percentage);
            }
            ptr = ptr->next;
        }
        printf("Enter roll no. to modify:");
        scanf("%d",&roll);
        modify_roll(roll);
        printf("Modified details:\n");
        print_rec_roll(roll);
    }
}

void modify_percentage(){
    float m;
    int c=0,roll;
    stu *ptr = headptr;
    printf("Enter percentage to search:");
    scanf("%f",&m);
    while(ptr){
        if(ptr->percentage==m){
            c++;
        }
        ptr = ptr->next;
    }
    if(c==0){
        printf("percentage not found\n");
        return;
    }
    else if(c==1){
        ptr = headptr;
        while(ptr){
            if(ptr->percentage==m){
            printf("Existing details:\n");
            print_rec_roll(ptr->rollno);
            printf("Enter students name:");
            scanf(" %[^\n]",ptr->name);
            while(1){
            printf("Enter student Percentage:");
            scanf("%f",&ptr->percentage);
            if(ptr->percentage >= 0 && ptr->percentage <=100){
                break;
            }
            printf("Percentage can only be between 0 to 100\n");
            }
            printf("Modified details:\n");
            print_rec_roll(ptr->rollno);
            return;
            }
            ptr = ptr->next;
        }
    }
    else{
        ptr = headptr;
        printf("More records found:\n");
        while(ptr){
            if(ptr->percentage==m){
                printf("%d %s %.2f\n",ptr->rollno,ptr->name,ptr->percentage);
            }
            ptr = ptr->next;
        }
        printf("Enter roll no. to modify:");
        scanf("%d",&roll);
        modify_roll(roll);
        printf("Modified details:\n");
        print_rec_roll(roll);
    }
}

void modify_rec(){
    char op;
    int roll;
    printf("Enter which record to search for modification\nR/r : Search by roll number\nN/n : Search by name\nP/p : Search by percentage\noption:");
    scanf(" %c",&op);
    switch(op){
        case ('R'):
        case ('r'):printf("Enter roll no to search:");scanf("%d",&roll);modify_roll(roll);break;
        case ('N'):
        case ('n'):modify_name();break;
        case ('P'):
        case ('p'):modify_percentage();break;
        default:printf("Enter valid option\n");
    }
}

int count_node(){
    int c=0;
    stu *ptr = headptr;
    while(ptr){
        c++;
        ptr = ptr->next;
    }
    return c;
}

void my_strcpy(char *d,char *s){
    
    while(*s){
        *d = *s;
        d++;
        s++;
    }
    *d='\0';
}

void sort_name(){
    if(headptr==0){
        printf("No records to sort\n");
        return;
    }
    int i,j,c=count_node();
    stu *s1,*s2,t;
    for(i=0;i<c-1;i++){
        s1 = headptr;
        for(j=0;j<c-1-i;j++){
            s2 = s1->next;
            if(my_strcmp(s1->name,s2->name)==-1){

                t.rollno = s1->rollno;
                s1->rollno = s2->rollno;
                s2->rollno = t.rollno;
                
                my_strcpy(t.name,s1->name);
                my_strcpy(s1->name,s2->name);
                my_strcpy(s2->name,t.name);

                t.percentage=s1->percentage;
                s1->percentage = s2->percentage;
                s2->percentage = t.percentage;
            }
            s1 = s1->next;
        }
    }
    printf("Sorted...\n");
}

void sort_percentage(){
    if(headptr==0){
        printf("No records to sort\n");
        return;
    }
    int i,j,c=count_node();
    stu *s1,*s2,t;
    for(i=0;i<c-1;i++){
        s1 = headptr;
        for(j=0;j<c-1-i;j++){
            s2 = s1->next;
            if(s1->percentage < s2->percentage){

                t.rollno = s1->rollno;
                s1->rollno = s2->rollno;
                s2->rollno = t.rollno;
            
                my_strcpy(t.name,s1->name);
                my_strcpy(s1->name,s2->name);
                my_strcpy(s2->name,t.name);

                t.percentage=s1->percentage;
                s1->percentage = s2->percentage;
                s2->percentage = t.percentage;
            }
            s1 = s1->next;
        }
    }
    printf("Sorted...\n");
}


void sort_rec(){
    char op;
    printf("N/n : Sort with name\nP/p : Sort with percentage\noption:");
    scanf(" %c",&op);
    switch(op){
        case ('N'):
        case ('n'):sort_name();break;
        case ('P'):
        case ('p'):sort_percentage();break;
        default:printf("Not a valid option\n");
    }
}

void reverse_links(){

    if(headptr==0){
        printf("No records to reverse\n");
        return;
    }
    int i,c=count_node();
    stu **a = malloc(sizeof(stu *)*c);
    if(c>1){
    stu *ptr = headptr;
    for(i=0;i<c;i++){
        a[i] = ptr;
        ptr = ptr->next;
    }
    for(i=c-1;i>0;i--){
        a[i]->next = a[i-1];
    }
    a[0]->next=0;
    headptr = a[c-1];

}
}