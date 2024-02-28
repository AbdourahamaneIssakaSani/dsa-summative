#include "list.h"

/**
* add_student_mid - Add a new student to the middle of the list
* @head: Pointer to the head of the list
* @new_student: Pointer to the new student
* @position: Position to add the new student
* Return: Pointer to the head of the list or NULL if invalid position
*/
student_t *add_student_mid(student_t *head,
						student_t *new_student, int position)
{
	student_t *temp = head;
	int i = 1;

	if (position == 0)
	{
		new_student->next = head;
		head = new_student;
		return (head);
	}

	while (i < position)
	{
		if (temp->next == NULL)
		{
			return (NULL);
		}
		temp = temp->next;
		i++;
	}

	new_student->next = temp->next;
	temp->next = new_student;

	return (head);
}
