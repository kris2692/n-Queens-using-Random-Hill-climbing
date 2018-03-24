# n-Queens-using-Random-Hill-climbing
Implementation of n-Queens using Random hill climbing algorithm
In this problem, we are supposed to place queens in a chess board of size n x n, such that no two queens attack each other. Two queens are said to be in attacking position if they are placed in the same row, same column and same diagonal.
Here, the board is generated randomly, with the queens already present. If in case the search gets stuck, due to the current cost being greater than previous one, a random board is generated and the whole search procedure starts all over again.
This program takes the number of queens as input. And the heuristic is the number of conflicts present in the board.
