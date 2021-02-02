#include <iostream>
using namespace std;

int max(int a, int b) {
    if (a > b){
        return a;
    }
    else {
         return b;
    }
}
int func (int W, int wt[], int val[], int n) {

    if (W == 0 || n == 0) {
        return 0;
    }
    if (wt[n-1] > W) {
        return func(W, wt, val, n-1);
    }
    else {
        return max(val[n-1] + func(W - wt[n-1], wt, val, n - 1), func (W, wt, val, n - 1));
    }
}

int main() {
    int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = 3; 
    cout << func(W, wt, val, n); 
    return 0; 
}

