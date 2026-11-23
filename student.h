#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
int rollno;
char name[50];
float percentage;
struct student *next;
}stu;

extern int rev;
extern stu *headptr ;

void add_new();
void print_rec();
void print_rec_roll(int);
int my_strcmp(char *,char *);
void delete_rec();
void modify_rec();
void save_rec();
void read_file();
void exit_rec();
void delete_all();
void sort_rec();
int count_node();
void reverse_links();