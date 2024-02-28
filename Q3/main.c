/*
* This program creates a list of students and performs some operations on it.

* The program uses the following functions:
* create_student - Create a new student
* add_student_end - Add a new student to the end of the list
* add_student_mid - Add a new student to the middle of the list
* delete_student - Delete a student from the list
* print_list - Print the list of students
*
* Compilation: gcc -o main Q3/main.c Q3/add_student_end.c Q3/add_student_mid.c Q3/create_student.c Q3/delete_student.c Q3/print_list.c
*
* Execution: ./main
*/

#include "list.h"

int main(void)
{
    student_t *head;
    student_t *student;

    char *email = malloc(100 * sizeof(char));
    int position;

    head = NULL;

    for (int i = 0; i < 10; i++)

    {
        char email_address[100];
        sprintf(email_address, "student%d@mail.com", i);

        student = create_student("Student", "Name", email_address, 20 + i);
        if (student == NULL)
        {
            return (1);
        }

        head = add_student_end(head, student);
    }

    printf("Initial list:\n");
    print_list(head);

    printf("\n\n=============================\n\n");
    printf("Enter the position to add the new student: ");
    scanf("%d", &position);

    student = create_student("New", "Student", "new@mail.com", 25);
    if (student == NULL)
    {
        return (1);
    }

    head = add_student_mid(head, student, position);

    printf("\n\n=============================\n\n");

    printf("List after adding the new student:\n");
    print_list(head);

    printf("\n\n=============================\n\n");
    printf("Enter the email of the student to delete: ");
    scanf("%s", email);

    head = delete_student(head, email);

    printf("\n\n=============================\n\n");

    printf("List after deleting the student:\n");

    print_list(head);

    return (0);
}
