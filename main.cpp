#include <knapsack.h>
#include <N_Queens.h>
#include <iostream>
using namespace std;

int main() {
    //code queens
    int grid[20][20];
    int offset[2] = { 0, 0 };
    int n = 2;
    int total = 0;
    newGrid(grid);
    cout << func(n, grid, total, 0) << endl;

    //code knapsack
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = 3;
    cout << func(W, wt, val, n);
 
    

	return 0;
}

