
//by Ali Eissa 900201885 and Seif Awad 
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
