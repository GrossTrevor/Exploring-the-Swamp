/*
    Exploring the swamp

    Explorer Albert, a coffee bean aficionado, is passing through a swamp while simultaneously
    trying to pick up as many coffee beans as possible. The swamp is represented by a m x n 
    integer array, swamp, where swamp[i][j] represents the number of coffee beans located at
    row i, column j of the swamp.

    Albert always enters the swamp at row 0, column 0, and always exits the swamp at row m, 
    column n. At each step, he moves either one unit to the right (across one column) or one
    unit down (across one row). When Albert visits swamp[i][j], he collects all the coffee beans
     at that location. Write a function that returns the maximum number of coffee beans that
    Albert can collect as he traverses through the swamp. Implement your solution using dynamic 
    programming.

    Sample Input:
        5 3 4
        8 6 9
        1 3 2
    
    Sample Output:
        30
*/
//Partner - Samantha Bennett
#include <iostream>
#include <cstdlib>
#include <vector>

using std::vector;

int swampExplorer(std::vector<std::vector<int>>& swamp_maze) {
    int r = swamp_maze.size();
    int c = swamp_maze[0].size();

    //Create dp vector to size of swamp_maze
    vector<vector<int>> dp(r, vector<int>(c, 0));
    dp[0][0] = swamp_maze[0][0];

    //Input total values across the first row
    for (int i = 1; i < r; i++) {
        dp[i][0] = dp[i - 1][0] + swamp_maze[i][0];
    }

    //Input total values down the first column
    for (int j = 1; j < c; j++) {
        dp[0][j] = dp[0][j - 1] + swamp_maze[0][j];
    }

    //Fill in the maze
    for (int k = 1; k < r; k++) {
        for (int l = 1; l < c; l++) {
            if (dp[k - 1][l] >= dp[k][l - 1])
                dp[k][l] = dp[k - 1][l] + swamp_maze[k][l];
            else
                dp[k][l] = dp[k][l - 1] + swamp_maze[k][l];
        }
    }
    return dp[r - 1][c - 1];
}