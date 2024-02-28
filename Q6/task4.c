#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

/*TODO: */

void heapifyUp(heap_t *heap, binary_tree_node_t *node);
void enqueue(heap_t *heap, void *value);
void heapifyDown(heap_t *heap, binary_tree_node_t *node);
void *dequeue(heap_t *heap);
void print_priority_queue(heap_t *heap);
void free_max_heap(heap_t *heap);
int int_cmp(void *p1, void *p2);
void print_in_order(binary_tree_node_t *node);
void free_heap(binary_tree_node_t *node);
void swap(void **a, void **b);

/**
 * main - Entry point
 * Return: 0 on success
 */
int main(void)
{
    int capacity = 10;
    heap_t *priority_queue = heap_create(int_cmp);

    enqueue(priority_queue, (void *)20);
    enqueue(priority_queue, (void *)10);
    enqueue(priority_queue, (void *)30);
    enqueue(priority_queue, (void *)40);
    enqueue(priority_queue, (void *)5);

    print_priority_queue(priority_queue);

    void *deq_element = dequeue(priority_queue);
    printf("Dequeued Element: %p\n", deq_element);

    print_priority_queue(priority_queue);

    free_max_heap(priority_queue);

    return 0;
}

/**
 * swap - Swap two integers
 * @a: pointer to the first integer
 * @b: pointer to the second integer

*/
void swap(void **a, void **b)
{
    void *temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * heapifyUp - Heapify the max heap
 * @heap: pointer to the max heap
 * @node: pointer to the heap node
 */
void heapifyUp(heap_t *heap, binary_tree_node_t *node)
{
    while (node->parent != NULL && heap->data_cmp(node->data, node->parent->data) > 0)
    {
        swap((void **)&node->data, (void **)&node->parent->data);
        node = node->parent;
    }
}

/**
 * enqueue - Insert a new node into the max heap
 * @heap: pointer to the max heap
 * @value: pointer to the new node's data
 * Return: pointer to the new node
 */
void enqueue(heap_t *heap, void *value)
{
    if (heap->size == 0)
    {
        heap->root = binary_tree_node(NULL, value);
    }
    else
    {
        binary_tree_node_t *newNode = binary_tree_node(NULL, value);
        binary_tree_node_t *lastNode = heap->root;

        while (lastNode->left != NULL)
        {
            lastNode = lastNode->left;
        }

        if (lastNode->left == NULL)
        {
            lastNode->left = newNode;
            newNode->parent = lastNode;
        }
        else if (lastNode->right == NULL)
        {
            lastNode->right = newNode;
            newNode->parent = lastNode;
        }

        heapifyUp(heap, newNode);
    }

    heap->size++;
}
/**
 * heapifyDown - Heapify the max heap
 * @heap: pointer to the max heap
 * @node: pointer to the heap node
 */
void heapifyDown(heap_t *heap, binary_tree_node_t *node)
{
    while ((node->left != NULL && heap->data_cmp(node->left->data, node->data) > 0) ||
           (node->right != NULL && heap->data_cmp(node->right->data, node->data) > 0))
    {
        binary_tree_node_t *max_child = (node->right == NULL || heap->data_cmp(node->left->data, node->right->data) > 0)
                                           ? node->left
                                           : node->right;

        swap((void **)&node->data, (void **)&max_child->data);
        node = max_child;
    }
}

/**
 * dequeue - Remove the root node from the max heap
 * @heap: pointer to the max heap
 * Return: pointer to the root node's data
 */
void *dequeue(heap_t *heap)
{
    if (heap->size == 0)
    {
        printf("Priority queue is empty. Cannot dequeue.\n");
        return NULL;
    }

    void *maxValue = heap->root->data;

    if (heap->size == 1)
    {
        free(heap->root);
        heap->root = NULL;
    }
    else
    {
        binary_tree_node_t *lastNode = heap->root;

        while (lastNode->left != NULL)
        {
            lastNode = lastNode->left;
        }

        swap((void **)&heap->root->data, (void *)&lastNode->data);
        if (lastNode->parent->left == lastNode)
        {
            free(lastNode->parent->left);
            lastNode->parent->left = NULL;
        }
        else if (lastNode->parent->right == lastNode)
        {
            free(lastNode->parent->right);
            lastNode->parent->right = NULL;
        }

        heapifyDown(heap, heap->root);
    }

    heap->size--;

    return maxValue;
}

/**
 * print_priority_queue - Print the priority queue
 * @heap: pointer to the max heap
 */
void print_priority_queue(heap_t *heap)
{
    printf("Priority Queue: ");
    print_in_order(heap->root);
    printf("\n");
}

/**
 * print_in_order - Print the heap in order
 * @node: pointer to the heap node
 */
void print_in_order(binary_tree_node_t *node)
{
    if (node != NULL)
    {
        print_in_order(node->left);
        printf("%p ", node->data);
        print_in_order(node->right);
    }
}

/**
 * free_max_heap - Free the max heap
 * @heap: pointer to the max heap
 */
void free_max_heap(heap_t *heap)
{
    free_heap(heap->root);
    free(heap);
}

/**
 * free_heap - Free the heap
 * @node: pointer to the heap node
 * Return: pointer to the heap node
 */
void free_heap(binary_tree_node_t *node)
{
    if (node != NULL)
    {
        free_heap(node->left);
        free_heap(node->right);
        free(node);
    }
}

/**
 * int_cmp - Compare two integers
 * @p1: Pointer to the first integer
 * @p2: Pointer to the second integer
 *
 * Return: Difference between the two integers
 */
int int_cmp(void *p1, void *p2)
{
    int n1 = *((int *)p1);
    int n2 = *((int *)p2);

    return n1 - n2;
}
