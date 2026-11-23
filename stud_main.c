#include"student.h"
stu *headptr=0;
int rev;
int main(){
    read_file();
    char op;
    while(1){
        printf("******** STUDENT RECORD MENU ********\n");
        printf("a/A : Add new record\nd/D : Delete a record\ns/S : Show the list\nm/M : Modify a record\nv/V : Save records\ne/E : Exit\nt/T : Sort the list\nl/L : Delete all the records\nr/R : Reverse the list\nOption:");
        scanf(" %c",&op);
        switch(op){
            case ('a'): 
            case ('A'):add_new();break;
            case ('d'):
            case ('D'):delete_rec();break;
            case ('s'):
            case ('S'):print_rec();break;
            case ('m'):
            case ('M'):modify_rec();break;
            case ('v'):
            case ('V'):save_rec();break;
            case ('e'):
            case ('E'):exit_rec();break;
            case ('t'):
            case ('T'):sort_rec();break;
            case ('l'):
            case ('L'):delete_all();break;
            case ('r'):
            case ('R'):reverse_links();break;
            default:printf("Enter valid option\n");
        }

    
    }

}