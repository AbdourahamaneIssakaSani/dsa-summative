#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* struct student - Student structure
* @first_name: First name of the student
* @last_name: Last name of the student
* @email: Email of the student. Unique in this case
* @age: Age
* @next: Pointer to the next student
*/
typedef struct student
{
	char first_name[50];

	char last_name[50];

	char email[100];

	int age;

	struct student *next;
} student_t;

student_t *add_student_mid(student_t *head,
						student_t *new_student, int position);

student_t *create_student(char *first_name,

						char *last_name, char *email, int age);

student_t *add_student_end(student_t *head, student_t *new_student);

student_t *delete_student(student_t *head, char *email);

void print_list(student_t *head);

#endif /* LIST_H */
