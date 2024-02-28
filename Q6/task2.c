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
	int largest = i;

	int left = 2 * i + 1;

	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

/**
* build_max_heap - Build max heap from the array
* @arr: array to build max heap
* @n: size of the array
*/
void build_max_heap(int arr[], int n)
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
* main - Entry point of the program
* Return: 0 on success
*/
int main(void)
{
	int random_arr[] = {4, 10, 3, 5, 1};

	int n = sizeof(random_arr) / sizeof(random_arr[0]);

	printf("Random input array: ");
	print_array(random_arr, n);

	build_max_heap(random_arr, n);

	printf("Max heap from random input array: ");
	print_array(random_arr, n);

	int sorted_arr[] = {10, 8, 7, 5, 2};

	n = sizeof(sorted_arr) / sizeof(sorted_arr[0]);

	printf("\nSorted input array: ");
	print_array(sorted_arr, n);

	build_max_heap(sorted_arr, n);

	printf("Max heap from sorted input array: ");
	print_array(sorted_arr, n);

	return (0);
}
