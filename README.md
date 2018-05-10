# n-Queens-using-Random-Hill-climbing
Implementation of n-Queens using Random hill climbing algorithm
In this problem, we are supposed to place queens in a chess board of size n x n, such that no two queens attack each other. Two queens are said to be in attacking position if they are placed in the same row, same column and same diagonal.
Here, the board is generated randomly, with the queens already present. If in case the search gets stuck, due to the current cost being greater than previous one, a random board is generated and the whole search procedure starts all over again.
This program takes the number of queens as input. And the heuristic is the number of conflicts present in the board.

# Random-restart Hill Climbing

 hill climbing is a mathematical optimization technique which belongs to the family of local search. It is an iterative algorithm that starts with an arbitrary solution to a problem, then attempts to find a better solution by incrementally changing a single element of the solution. If the change produces a better solution, an incremental change is made to the new solution, repeating until no further improvements can be found. Hill climbing is an anytime algorithm: it can return a valid solution even if it's interrupted at any time before it ends. Random-restart hill climbing is a meta-algorithm built on top of the hill climbing algorithm. It is also known as Shotgun hill climbing. It iteratively does hill-climbing, each time with a random initial condition {\displaystyle x_{0}} x_{0}. The best {\displaystyle x_{m}} x_{m} is kept: if a new run of hill climbing produces a better {\displaystyle x_{m}} x_{m} than the stored state, it replaces the stored state.

Random-restart hill climbing is a surprisingly effective algorithm in many cases. It turns out that it is often better to spend CPU time exploring the space, than carefully optimizing from an initial condition.

