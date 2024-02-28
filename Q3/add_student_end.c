#include "list.h"

/**
* add_student_end - Add a new student to the end of the list
* @head: Pointer to the head of the list
* @new_student: Pointer to the new student
* Return: Pointer to the head of the list
*/
student_t *add_student_end(student_t *head, student_t *new_student)
{
	student_t *temp = head;

	if (head == NULL)
	{
		head = new_student;
		return (head);
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = new_student;

	return (head);
}
