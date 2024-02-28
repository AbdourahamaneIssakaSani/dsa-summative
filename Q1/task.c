/*
 * Program to sort usernames using the merge sort algorithm
 *
 * Compilation: gcc -o task Q1/task.c
 *
 * Execution: ./task
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * merge - Merge function to merge two sorted arrays
 * @arr: array of usernames
 * @left: left index of the array
 * @mid: middle index of the array
 * @right: right index of the array
 */
void merge(char **arr, int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char **L = (char **)malloc(n1 * sizeof(char *));
    char **R = (char **)malloc(n2 * sizeof(char *));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (strcmp(L[i], R[j]) <= 0)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

/**
 * merge_sort - Merge sort algorithm to sort the usernames
 * @arr: array of usernames
 * @left: left index of the array
 * @right: right index of the array
 */
void merge_sort(char **arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

/**
 * main - Entry point of the program
 * Return: 0 on success, 1 on memory allocation failure
 */
int main()
{
    int n;
    printf("Enter the number of usernames: ");
    scanf("%d", &n);

    char **usernames = (char **)calloc(n, sizeof(char *));
    if (!usernames)
    {
        perror("Memory allocation failed");
        return 1;
    }

    printf("Enter the usernames:\n");
    for (int i = 0; i < n; i++)
    {
        usernames[i] = (char *)malloc(100 * sizeof(char));
        if (!usernames[i])
        {
            perror("Memory allocation failed");
            return 1;
        }
        scanf("%s", usernames[i]);
    }

    merge_sort(usernames, 0, n - 1);

    printf("Sorted usernames:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", usernames[i]);
        free(usernames[i]);
    }

    free(usernames);

    return 0;
}