# Question 2: Dynamic Programming

In the provided code, we have implemented two different approaches to calculate the Fibonacci series: the recursive approach and the memoized (dynamic programming) approach.

## Dynamic Programming vs. Recursion

### Recursive Fibonacci

case n = 48

```plaintext
Choose the method to calculate Fibonacci Series:
1. Recursive
2. Memoization
1
Enter the value of n: 48
Recursive Fibonacci Series up to 48 terms:
0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 10946 17711 28657 46368 75025 121393 196418 317811 514229 832040 1346269 2178309 3524578 5702887 9227465 14930352 24157817 39088169 63245986 102334155 165580141 267914296 433494437 701408733 1134903170 1836311903 2971215073
Recursive Fibonacci Time: 71.374297 second
```

case n = 50

```plaintext
Choose the method to calculate Fibonacci Series:
1. Recursive
2. Memoization
1
Enter the value of n: 48
Recursive Fibonacci Series up to 48 terms:
0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 10946 17711 28657 46368 75025 121393 196418 317811 514229 832040 1346269 2178309 3524578 5702887 9227465 14930352 24157817 39088169 63245986 102334155 165580141 267914296 433494437 701408733 1134903170 1836311903 2971215073
Recursive Fibonacci Time: 71.374297 second
```

The recursive Fibonacci implementation calculates each Fibonacci number by recursively calling the function for the previous two numbers until reaching the base case (n <= 1). While this approach is simple and intuitive, it becomes highly inefficient for larger values of n due to redundant calculations. As evident from the timing information,  it takes a substantial amount of time (71.37 seconds) to compute the Fibonacci series up to 48 terms. For 50 terms, it takes approximately 3.23 minutes (193.59 seconds), and if you input 100 terms, it becomes impractical and takes a very long time. This highlights the exponential time complexity of the recursive Fibonacci algorithm, making it inefficient for large values of n.

### Memoized Fibonacci (Dynamic Programming)

case n = 48

```plaintext
Choose the method to calculate Fibonacci Series:
1. Recursive
2. Memoization
2
Enter the value of n: 48
Memoized Fibonacci Series up to 48 terms:
0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 10946 17711 28657 46368 75025 121393 196418 317811 514229 832040 1346269 2178309 3524578 5702887 9227465 14930352 24157817 39088169 63245986 102334155 165580141 267914296 433494437 701408733 1134903170 1836311903 2971215073
Memoized Fibonacci Time: 0.000011 seconds
```

case n = 50

```plaintext
Choose the method to calculate Fibonacci Series:
1. Recursive
2. Memoization
2
Enter the value of n: 50
Memoized Fibonacci Series up to 50 terms:
0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 10946 17711 28657 46368 75025 121393 196418 317811 514229 832040 1346269 2178309 3524578 5702887 9227465 14930352 24157817 39088169 63245986 102334155 165580141 267914296 433494437 701408733 1134903170 1836311903 2971215073 4807526976 7778742049
Memoized Fibonacci Time: 0.000007 seconds
```

case n = 100

```plaintext
Choose the method to calculate Fibonacci Series:
1. Recursive
2. Memoization
2
Enter the value of n: 100
Memoized Fibonacci Series up to 100 terms:
0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 10946 17711 28657 46368 75025 121393 196418 317811 514229 832040 1346269 2178309 3524578 5702887 9227465 14930352 24157817 39088169 63245986 102334155 165580141 267914296 433494437 701408733 1134903170 1836311903 2971215073 4807526976 7778742049 12586269025 20365011074 32951280099 53316291173 86267571272 139583862445 225851433717 365435296162 591286729879 956722026041 1548008755920 2504730781961 4052739537881 6557470319842 10610209857723 17167680177565 27777890035288 44945570212853 72723460248141 117669030460994 190392490709135 308061521170129 498454011879264 806515533049393 1304969544928657 2111485077978050 3416454622906707 5527939700884757 8944394323791464 14472334024676221 23416728348467685 37889062373143906 61305790721611591 99194853094755497 160500643816367088 259695496911122585 420196140727489673 679891637638612258 1100087778366101931 1779979416004714189 2880067194370816120 4660046610375530309 7540113804746346429 12200160415121876738 1293530146158671551 13493690561280548289 14787220707439219840 9834167195010216513 6174643828739884737 16008811023750101250
Memoized Fibonacci Time: 0.000054 seconds
```

The memoized Fibonacci implementation utilizes dynamic programming by storing the results of previous calculations in a memoization array. When a Fibonacci number is needed, it first checks if it has already been calculated and stored in the memoization array. If so, it directly retrieves the value, avoiding redundant calculations. This results in significantly improved efficiency. As seen from the timing information, the memoized approach takes only 0.000011 seconds  to compute the Fibonacci series up to 48 terms,  0.000007 seconds for 50 terms and Time: 0.000054 seconds for 100 terms, which is much faster than the recursive approach.

## Key Differences

- Redundant Calculations: The recursive approach recalculates Fibonacci numbers multiple times, leading to inefficiency. In contrast, the memoized approach stores previously calculated values, avoiding redundant computations.

- Time Complexity: The time complexity of the recursive approach is exponential (O(2^n)), while the memoized approach has a linear time complexity (O(n)). This significant reduction in time complexity makes dynamic programming more scalable for larger datasets.
