#include "list.h"

/**
* delete_student - Delete a student from the list
* @head: Pointer to the head of the list
* @email: Email of the student to delete
* Return: Pointer to the head of the list
*/
student_t *delete_student(student_t *head, char *email)
{
	student_t *temp = head;
	student_t *prev = NULL;

	if (temp != NULL && strcmp(temp->email, email) == 0)
	{
		head = temp->next;
		free(temp);
		return (head);
	}

	while (temp != NULL && strcmp(temp->email, email) != 0)
	{
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL)
	{
		return (head);
	}

	if (prev != NULL)
	{
		prev->next = temp->next;
	}

	free(temp);

	return (head);
}
