typedef struct Student {
  char *lastname;
  char *firstname;
  long id;
  char *year; 
  int grad_year; 
  struct Student *next;
  struct Student *prev;
} Student;

typedef struct StudentList {
  Student *head;
  Student *tail;
  int size;
} StudentList;

void print_student(Student *student);
void add_student(StudentList *list, Student student);
void remove_student(StudentList *list, char *lastname);
void print_students(StudentList *list);
void print_backwards(StudentList *list);
void exit();