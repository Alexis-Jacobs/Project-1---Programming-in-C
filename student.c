#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void print_student(Student *student){
    //Simple function to print out all the information of a student.
    //Included for the sake of printing forwards and backwards.
    printf("Last Name: %s\n", student->lastname);
    printf("First Name: %s\n", student->firstname);
    printf("ID: %ld\n", student->id);
    printf("Year: %s\n", student->year);
    printf("Graduation Year: %d\n", student->grad_year);
}

void add_student(StudentList *list, Student student){
    //Allocate the correct memory for the new student, ensure the right amount is allocated, copy user-entered stuent information
    //into the new student, and add the new student to the end of the list. If the list is empty, set the head and tail to the new student.
    Student *new_student = (Student*)malloc(sizeof(Student));

    // if(new_student == NULL){
    //     printf("Memory allocation failed\n");
    //     return 0;
    // }

    *new_student = student;

    new_student->next=NULL;
    new_student->prev=list->tail;
    new_student->lastname = strdup(student.lastname);
    new_student->firstname = strdup(student.firstname);
    new_student->year = strdup(student.year);
    new_student->id = student.id;
    new_student->grad_year = student.grad_year;

    if(list->head == NULL){
        list->head = new_student;
        list->tail = new_student;
        list->size = 1;
    } else {
        list->tail->next = new_student;
        list->tail = new_student;
        list->size++;
    }
    return;
}

void remove_student(StudentList *list, char *lastname){
    //rmove student from the list, depending on where it is in the list. Deallocated memory for that student in the list.
    Student *temp = list->head;
    if(list->head == NULL){
        printf("List is empty\n");
        return;
    }else{
        while(temp != NULL){
            Student *nextStd = temp->next;
            if(strcmp(temp->lastname, lastname) == 0){
                //connect the previous and next students together, if they exist. If not, set the head or tail to the next or previous student.
                printf("Removing student: %s %s\n", temp->firstname, temp->lastname);
                if(temp-> prev != NULL){
                    temp->prev->next = temp->next;
                }else{
                    list->head = temp->next;
                    //temp->next->prev = NULL;
                }
                if(temp->next != NULL){
                    temp->next->prev = temp->prev;
                }else{
                    list->tail = temp->prev;
                    //temp->prev->next = NULL;
                }
                free(temp->lastname);
                free(temp->firstname);
                free(temp->year);
                free(temp);
                list->size--;
            }
            temp = nextStd;
        }
    }
    return;
}

void print_students(StudentList *list){
    //prints all students in the list starting at the head going to the tail
    if(list->head == NULL){
        printf("List is empty\n");
        return;
    }else{
         Student *temp = list->head;
        for(int i=0; i<list->size; i++){
            print_student(temp);
            printf("\n");
            temp = temp->next;
        }
    }
    return;
}
void print_backwards(StudentList *list){
    //prints all students in the list starting at the tail going to the head
    if(list->tail == NULL){
        printf("List is empty\n");
        return;
    }else{
        Student *temp = list->tail;
        for(int i=0; i<list->size; i++){
            print_student(temp);
            printf("\n");
            temp = temp->prev;
        }
    }
    return;
}
void exit_program(StudentList *list){
    //deallocate all memory for the list and all students in the list, then free the list itself.
    Student *temp = list->head;
    while(temp != NULL){
        Student *next = temp->next;
        free(temp);
        temp = next;
    }
    return;
}