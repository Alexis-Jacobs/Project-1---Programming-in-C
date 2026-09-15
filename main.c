#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

#define BUFFERSIZE 128


int main() {
    StudentList list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;

    char buffer[BUFFERSIZE];
    int choice;
    int Continue = 1;
    while(Continue == 1){
        printf("\n");
        printf("-------------------------------\n");
        printf("Choose one option from below\n");
        printf("1. Add a student\n");
        printf("2. Remove a student\n");
        printf("3. Print all students\n");
        printf("4. Print all students backwards\n");
        printf("5. Exit program\n");
        printf("Enter a number below: \n");
    
        if(fgets(buffer, BUFFERSIZE, stdin) == NULL) { 
            //get input from user, place in buffer variable, make sure no longer than buffer size, input comes through keyboard.
            //Makes sure input is valid before continuing. If not valid, print error message and continue to next iteration of loop.
            printf("Error reading input\n");
            break;
        }

        choice = atoi(buffer); //convert string to integer

        if(choice == 1){
            Student student;
            printf("Enter last name: ");
            fgets(buffer, BUFFERSIZE, stdin);
            buffer[strcspn(buffer, "\n")] = 0; //remove newline character
            student.lastname = strdup(buffer); //duplicate string and assign to student.lastname

            printf("Enter first name: ");
            fgets(buffer, BUFFERSIZE, stdin);
            buffer[strcspn(buffer, "\n")] = 0; //remove newline character
            student.firstname = strdup(buffer); //duplicate string and assign to student.firstname

            printf("Enter ID: ");
            fgets(buffer, BUFFERSIZE, stdin);
            student.id = atol(buffer); //convert string to long and assign to student.id

            printf("Enter year (Freshman, Senior, Graduate, etc.): ");
            fgets(buffer, BUFFERSIZE, stdin);
            buffer[strcspn(buffer, "\n")] = 0; //remove newline character
            student.year = strdup(buffer); //duplicate string and assign to student.year

            printf("Enter graduation year: ");
            fgets(buffer, BUFFERSIZE, stdin);
            student.grad_year = atoi(buffer); //convert string to integer and assign to student.grad_year

            add_student(&list, student); //add student to list
        } else if(choice == 2){
            printf("Enter last name of student to remove: ");
            fgets(buffer, BUFFERSIZE, stdin);
            buffer[strcspn(buffer, "\n")] = 0; //remove newline character
            remove_student(&list, buffer); //remove student from list
        } else if(choice == 3){
            print_students(&list); //print all students in list
        } else if(choice == 4){
            print_backwards(&list); //print all students in list backwards
        } else if(choice == 5){
            exit_program(&list); //exit program
            Continue = 0; //set Continue to 0 to exit loop
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}