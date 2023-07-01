// 1.Recursive function:
int F(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else {
        return F(n-3) + F(n-2);
    }
}
/*
    This is the simplest way to implement the recurrence relation. 
    The function calls itself with smaller inputs, 
    until it reaches the base case. However, 
    this method suffers from the problem of overlapping subproblems, 
    as the same values are recalculated multiple times. 
    This leads to a large number of function calls and a large amount of time complexity, 
    making this method inefficient for large values of n.
*/

// 2. Dynamic Programming:
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

int cache[MAX_N];

int F(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else if (cache[n] != -1) {
        return cache[n];
    } else {
        cache[n] = F(n-3) + F(n-2);
        return cache[n];
    }
}

int main() {
    int n;
    for (int i = 0; i < MAX_N; i++) {
        cache[i] = -1;
    }
    scanf("%d", &n);
    printf("%d\n", F(n));
    return 0;
}
/*
    This method is more efficient than the previous one as it stores the results of previously computed subproblems in an array (cache). 
    The function checks the cache before computing the value, and returns the cached value if it exists,
     avoiding redundant function calls and greatly reducing the time complexity. However, this method requires additional space complexity to store the cache, 
     and the size of the cache needs to be determined in advance.
*/

// 3. Iterative function:
int F(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else {
        int a = 0, b = 1, c = 2;
        for (int i = 3; i <= n; i++) {
            int tmp = a + b + c;
            a = b;
            b = c;
            c = tmp;
        }
        return c;
    }
}
/*
    This method eliminates the problem of overlapping subproblems by iteratively computing the values of F(n) without recursion. 
    This method is more space-efficient than the dynamic programming method as it only requires a constant amount of memory. However, 
    it may require more complex code to implement the iterative process.
*/

// 4.Tabulation Function
int F(int n) {
  int memo[n + 1];
  memo[0] = 0;
  memo[1] = 1;
  memo[2] = 2;
  for (int i = 3; i <= n; i++) {
    memo[i] = memo[i - 3] + memo[i - 2];
  }
  return memo[n];
}
/*
This is the most efficient way to implement the recurrence relation.
 It uses a table to store the values of F(0), F(1), ..., F(n) so that they can be looked up directly.
*/
// 4.Memoization  Function
int F(int n, int *memo) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else if (n == 2) {
    return 2;
  } else if (memo[n] == 0) {
    memo[n] = F(n - 3, memo) + F(n - 2, memo);
  }
  return memo[n];
}

/*
This is a more efficient way to implement the recurrence relation. 
It uses a memoization table to store the values of F(n-3) and F(n-2) so that they don't have to be recalculated every time.
*/


/*
Implementation	   Advantages	                           Disadvantages
Recursive	      Simple to implement	                     Inefficient
Memoized	      More efficient than recursive	         More difficult to implement
Tabulated	      Most efficient	                         Most difficult to implement

*/
// SUMMARY
/*
    In summary, the recursive method is simple to implement but inefficient for large values of n, 
    the dynamic programming method is more efficient but requires additional space complexity,
     and the iterative method is space-efficient but may require more complex code.
*/
