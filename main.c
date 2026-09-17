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
        //Print statements are for user interface, to display options to the user 
        //and establish what the user can do/ make the program look pretty
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
            //If user chooses to add a student, prompt user for student information and store in new student struct
            Student student;
            printf("Enter last name: ");
            fgets(buffer, BUFFERSIZE, stdin); //This line was asissted by ChatGPT 5.6, prompt "Can you explain how fgets() works in C?"
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
            //If remove student is selected, get the last name of the student that the user wishes to remove
            printf("Enter last name of student to remove: ");
            fgets(buffer, BUFFERSIZE, stdin);
            buffer[strcspn(buffer, "\n")] = 0; //remove newline character
            remove_student(&list, buffer); //remove student from list
        } else if(choice == 3){
            //if print is chosen, call print students
            print_students(&list); //print all students in list
        } else if(choice == 4){
            //if print backwards is chosen, call print backwards
            print_backwards(&list); //print all students in list backwards
        } else if(choice == 5){
            //if exit is chosen, call exit program and set Continue to 0 to exit loop
            exit_program(&list); //exit program
            Continue = 0; //set Continue to 0 to exit loop
        } else {
            //if user enters an invalid choice, print error message
            printf("Invalid choice\n");
        }
    }
    return 0;
}