#include <iostream>
#include <cmath>
using namespace std;


void updateGrid(int grid[][20], int x, int y) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if ((i == x || j == y) && grid[i][j] == 0) {
                grid[i][j] = 2;
            }
            if (abs(i - x) == abs(j - y) && grid[i][j] == 0) {
                grid[i][j] = 2;
            }
        }
    }
}
void copyGrid(int grid[][20], int grid1[][20]) {
    for (int i = 0; i < 20*20; i++) { // prefill with zeros
        grid[i % 20][i - (i % 20)*20] = grid1[i % 20][i - (i % 20)*20];
    }
}

int func (int &N, int grid[][20], int &total, int row) {
    bool done = false;
    if (N > 20) { // reset and offset
        return 0;
    }
    if (total == N) {
        cout << "done" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
        return N;
    } 
    else {
        bool done = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 0) {
                    grid[i][j] = 1;
                    total++;
                    int gridInstance[20][20];
                    copyGrid(gridInstance, grid);
                    gridInstance[i][j] = 1;
                    updateGrid(gridInstance, i, j);
                    if (row == 20) {
                        for (int i = 0; i < N; i++) {
                            for (int j = 0; j < N; j++) {
                                cout << grid[i][j];
                            }
                            cout << endl;
                        }
                        return 0;
                    }
                    
                    int result = func(N, gridInstance, total, row++);
                    if (result != 0) {
                        return result;
                    }
                    
                    copyGrid(gridInstance, grid);
                    
                }
            }
            if (i == N - 1) {
                N++;
                i = 0;
            }
        }
                
    }
}
void newGrid(int grid[][20]) {
    for (int i = 0; i < 20*20; i++) { // prefill with zeros
        grid[i % 20][i - (i % 20)*20] = 0;
    }
}


int main() { // the queens are labeled as 1, invalid places labeled as 2, empty places as 0
    int grid[20][20]; 
    int offset[2] = {0, 0};
    int n = 2;
    int total = 0;
    newGrid(grid);
    cout << func(n, grid, total, 0) << endl; 
    
    return 0; 
}
