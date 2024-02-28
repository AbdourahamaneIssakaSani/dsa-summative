#include "list.h"

/**
* print_list - Print all the elements of a list
* @head: Pointer to the head of the list
*/
void print_list(student_t *head)
{
	student_t *temp = head;

	while (temp != NULL)
	{
		printf("Name: %s %s, Email: %s, Age: %d\n",
			temp->first_name, temp->last_name,
			temp->email, temp->age);
		temp = temp->next;
	}
}
