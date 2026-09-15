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

    if(new_student == NULL){
        printf("Memory allocation failed\n");
        return 0;
    }

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
    return 0;
}

void remove_student(StudentList *list, char *lastname){
    //rmove student from the list, depending on where it is in the list. Deallocated memory for that student in the list.
    if(list->head == NULL){
        printf("List is empty\n");
        return 0;
    }else{
        Student *temp = list->head;
        while(temp != NULL){
            if(strcmp(temp->lastname, lastname) == 0){
                if(temp->prev != NULL && temp->next != NULL){
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                else if(temp->prev != NULL){
                    temp->prev->next = temp->next;
                }else if(temp->next != NULL){
                    temp->next->prev = temp->prev;
                }else{
                    list->tail = temp->prev;
                }
                Student *found = temp;
                list->size--;
                temp = temp->next;
                free(found->lastname);
                free(found->firstname);
                free(found->year);
                free(found);
                break;
                //return 0;
            }
            temp = temp->next;
        }
        //printf("Student not found\n");
    }
    return 0;
}

void print_students(StudentList *list){
    //prints all students in the list starting at the head going to the tail
    if(list->head == NULL){
        printf("List is empty\n");
        return 0;
    }else{
        for(int i=0; i<list->size; i++){
            Student *temp = list->head;
            print_student(temp);
            temp = temp->next;
        }
    }
    return 0;
}
void print_backwards(StudentList *list){
    //prints all students in the list starting at the tail going to the head
    if(list->tail == NULL){
        printf("List is empty\n");
        return 0;
    }else{
        for(int i=0; i<list->size; i++){
            Student *temp = list->tail;
            print_student(temp);
            temp = temp->prev;
        }
    }
    return 0;
}
void exit(StudentList *list){
    //deallocate all memory for the list and all students in the list, then free the list itself.
    Student *temp = list->head;
    while(temp != NULL){
        Student *next = temp->next;
        free(temp);
        temp = next;
    }
    free(list);
    return 0;
}