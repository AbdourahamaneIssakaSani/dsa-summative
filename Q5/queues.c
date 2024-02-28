#include "queues.h"

/**
* queue_create - Initializes a queue structure
*
* Return: A pointer to the allocated structure, NULL on failure
*/
queue_t *queue_create(void)
{
	queue_t *new_queue = malloc(sizeof(queue_t));

	if (new_queue == NULL)
		return (NULL);

	new_queue->front = NULL;
	new_queue->back = NULL;
	return (new_queue);
}

/**
* queue_push_back - Pushes an element at the back of a queue
*
* @queue: Pointer to the queue
* @ptr: Data to store in the new node
*
* Return: A pointer to the created node, NULL on failure
*/
queue_node_t *queue_push_back(queue_t *queue, void *ptr)
{
	if (queue == NULL)
		return (NULL);

	queue_node_t *new_node = malloc(sizeof(queue_node_t));

	if (new_node == NULL)
		return (NULL);

	new_node->ptr = ptr;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (queue->back == NULL)
	{
		queue->front = new_node;
		queue->back = new_node;
	}
	else
	{
		new_node->prev = queue->back;
		queue->back->next = new_node;
		queue->back = new_node;
	}

	return (new_node);
}

/**
* queue_push_front - Pushes an element at the front of a queue
*
* @queue: Pointer to the queue
* @ptr: Data to store in the new node
*
* Return: A pointer to the created node, NULL on failure
*/
queue_node_t *queue_push_front(queue_t *queue, void *ptr)
{
	if (queue == NULL)
		return (NULL);

	queue_node_t *new_node = malloc(sizeof(queue_node_t));

	if (new_node == NULL)
		return (NULL);

	new_node->ptr = ptr;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (queue->front == NULL)
	{
		queue->front = new_node;
		queue->back = new_node;
	}
	else
	{
		new_node->next = queue->front;
		queue->front->prev = new_node;
		queue->front = new_node;
	}

	return (new_node);
}

/**
* dequeue - Pops out the front node of a queue
*
* @queue: Pointer to the queue
*
* Return: A pointer to the data of the popped node, NULL on failure
*/
void *dequeue(queue_t *queue)
{
	if (queue == NULL || queue->front == NULL)
		return (NULL);

	queue_node_t *front_node = queue->front;
	void *data = front_node->ptr;

	if (queue->front == queue->back)
	{
		queue->front = NULL;
		queue->back = NULL;
	}
	else
	{
		queue->front = front_node->next;
		queue->front->prev = NULL;
	}

	free(front_node);
	return (data);
}

/**
* queue_delete - Deallocates a queue
*
* @queue: Pointer to the queue to be deleted
*/
void queue_delete(queue_t *queue)
{
	if (queue == NULL)
		return;

	while (queue->front != NULL)
	{

		dequeue(queue);
	}

	free(queue);
}
