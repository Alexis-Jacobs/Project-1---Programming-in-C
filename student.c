#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void add_student(StudentList *list, Student student);
void remove_student(StudentList *list, char *lastname);
void print_students(StudentList *list);
void print_backwards(StudentList *list);
void exit();