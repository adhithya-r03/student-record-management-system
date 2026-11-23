# Student Database Management System (C / Linked List)

A console-based Student Database Management System written in **C** using a dynamically allocated **singly linked list**, with file persistence, record sorting/reversing, automatic unique roll number assignment, and input validation.

## Features

- **Dynamic Linked List Storage**: Stores student records in heap memory (`rollno`, `name`, `percentage`) without a fixed record cap.
- **Automatic Unique Roll Number Assignment**: Finds the smallest available positive roll number (`1, 2, 3, ...`) not currently in use, even after deletions, sorting, or list reversal.
- **Add, Display, Modify & Delete Records**: Manage student entries interactively with clean `%.2f` percentage formatting.
- **Sorting & Link Reversal**: Sort records or reverse node links using pointer manipulation while keeping each student's fields intact.
- **Input Validation**: Guards against empty or whitespace-only names, buffer/newline issues, and out-of-range or malformed inputs.
- **File Persistence**: Saves and loads student records from a data file (e.g., `student.dat` / `students.txt`) across program runs.

## Data Structure

Each node in the linked list represents a student record:

```c
typedef struct student {
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
} stu;
```

## Project Structure
```text
.
├── main.c          # Menu loop and program entry point
├── stud_add.c      # Add student & next available roll number logic
├── stud_show.c     # Display records with %.2f percentage formatting
├── stud_mod.c      # Modify existing student records
├── stud_del.c      # Delete student nodes and free memory
├── stud_sort.c     # Sort / reverse linked list nodes
├── stud_file.c     # Save to and load from file
├── validate.c      # Input reading and validation helpers
└── README.md
```
