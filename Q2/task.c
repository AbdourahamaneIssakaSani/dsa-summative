/*
 * Fibonacci Series using Recursion and Memoization
 *
 * File: task.c
 *
 * Compilation: gcc -o task Q2/task.c
 *
 * Execution: ./task
 *
 */

#include <stdio.h>
#include <time.h>

/**
 * rec_fibonacci - Recursive function to calculate the Fibonacci series
 * @n: number of terms
 * Return: Fibonacci series
 */
size_t rec_fibonacci(int n)
{
    if (n <= 1)
    {
        return (n);
    }
    return (rec_fibonacci(n - 1) + rec_fibonacci(n - 2));
}

/**
 * mem_fibonacci - Memoized function to calculate the Fibonacci series
 * @n: number of terms
 * @memo: array to store the memoized values
 * Return: Fibonacci series
 */
size_t mem_fibonacci(int n, size_t *memo)
{
    if (memo[n] != -1)
    {
        return (memo[n]);
    }
    if (n <= 1)
    {
        memo[n] = n;
    }
    else
    {
        memo[n] = mem_fibonacci(n - 1, memo) + mem_fibonacci(n - 2, memo);
    }
    return (memo[n]);
}

/**
 * main - Entry point of the program
 * Return: 0 on success
 */
int main(void)
{
    int choice, n;

    printf("Choose the method to calculate Fibonacci Series:\n");
    printf("1. Recursive\n");
    printf("2. Memoization\n");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2)
    {
        printf("Invalid choice.\n");
        return 1;
    }

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (choice == 1)
    {

        printf("Recursive Fibonacci Series up to %d terms:\n", n);
        clock_t start_rec = clock();
        for (int i = 0; i < n; i++)
        {
            printf("%zu ", rec_fibonacci(i));
        }
        clock_t end_rec = clock();
        double rec_time = ((double)(end_rec - start_rec)) / CLOCKS_PER_SEC;
        printf("\nRecursive Fibonacci Time: %f seconds\n", rec_time);
    }

    if (choice == 2)
    {

        printf("Memoized Fibonacci Series up to %d terms:\n", n);
        size_t memo[n + 1];
        for (int i = 0; i <= n; i++)
        {
            memo[i] = -1;
        }
        clock_t start_mem = clock();
        for (int i = 0; i < n; i++)
        {
            printf("%zu ", mem_fibonacci(i, memo));
        }
        clock_t end_mem = clock();
        double mem_time = ((double)(end_mem - start_mem)) / CLOCKS_PER_SEC;
        printf("\nMemoized Fibonacci Time: %f seconds\n", mem_time);
    }

    return 0;
}