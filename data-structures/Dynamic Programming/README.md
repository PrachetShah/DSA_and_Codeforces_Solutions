## Dynamic Programming Concepts

### Common Methods to breakdown DP sums:

- Find variable to process (index)
- Do stuff on the variable
- Maximise/Minimise/Count the solutions

Try creating recurrence relation alongside recurrence tree to understand the problem better

### To solve DP Problems, consider breaking down problem into 3 ways

- First, Recursion Problem,
  Create Recursion Tree to visualise the problem in hand, and find the overlapping subproblems

- Second, Create a memoization approach to reduce the calls taken
  To define the state of problem, find all the variables which are used, like index, lastIndex (for eg
  day, and last task in NinjasTraining Problem), and create dp array with that size of dp[n][tasks]

- Third, then create a tabulation approach on the problem to reduce stack space and further optimise the problem

- Fourth, if possible do space optimisation by reducing the space required using variables or 1D array instead of 2D array

### Concepts

- Recursion is Top-Down Approach i.e from (n -> 0) [Since, the value is returned from base case upto the top]
- Memoization is Top-Down Approach i.e from (n -> 0)
- Tabulation is Bottom-Up Approach i.e from (0 -> n)
