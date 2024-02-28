#include "list.h"

/**
* create_student - Create a new student
* @first_name: First name of the student
* @last_name: Last name of the student
* @email: Email
* @age: Age
* Return: Pointer to the new student
*/
student_t *create_student(char *first_name,

						char *last_name, char *email, int age)
{
	student_t *new_student = malloc(sizeof(student_t));

	if (new_student == NULL)
	{
		return (NULL);
	}
	strcpy(new_student->first_name, first_name);
	strcpy(new_student->last_name, last_name);
	strcpy(new_student->email, email);

	new_student->age = age;
	new_student->next = NULL;

	return (new_student);
}
