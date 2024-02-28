#include <stdio.h>
#include <stdlib.h>

/**
* swap - Swap two integers
* @a: Pointer to the first integer
* @b: Pointer to the second integer
*/
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
* heapify - Heapify the array
* @arr: array to heapify
* @n: size of the array
* @i: index of the array
*/
void heapify(int arr[], int n, int i)
{
	int smallest = i;

	int left = 2 * i + 1;

	int right = 2 * i + 2;

	if (left < n && arr[left] < arr[smallest])
		smallest = left;

	if (right < n && arr[right] < arr[smallest])
		smallest = right;

	if (smallest != i)
	{
		swap(&arr[i], &arr[smallest]);
		heapify(arr, n, smallest);
	}
}

/**
* build_min_heap - Build min heap from the array
* @arr: array to build min heap
* @n: size of the array
*/
void build_min_heap(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)

	{
		heapify(arr, n, i);
	}
}

/**
* print_array - Print the array
* @arr: array to print
* @size: size of the array
*/
void print_array(int arr[], int size)
{
	for (int i = 0; i < size; i++)

		printf("%d ", arr[i]);
	printf("\n");
}

/**
* main - Entry point
*
* Return: Always 0
*/
int main(void)
{
	int random_arr[] = {4, 10, 3, 5, 1};

	int n = sizeof(random_arr) / sizeof(random_arr[0]);

	printf("Random input array: ");
	print_array(random_arr, n);

	build_min_heap(random_arr, n);

	printf("Min heap from random input array: ");
	print_array(random_arr, n);

	int sorted_arr[] = {10, 8, 7, 5, 2};

	n = sizeof(sorted_arr) / sizeof(sorted_arr[0]);

	printf("\nSorted input array: ");
	print_array(sorted_arr, n);

	build_min_heap(sorted_arr, n);

	printf("Min heap from sorted input array: ");
	print_array(sorted_arr, n);

	return (0);
}
