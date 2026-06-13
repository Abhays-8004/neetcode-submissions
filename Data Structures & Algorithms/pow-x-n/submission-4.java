class Solution {
    double solve(double x,int n){
        if(n == 1)return x;
        double res = solve(x,n/2);
        if(n%2 !=0){
            return res*res*x;
        }
        return res*res;
    }
    public double myPow(double x, int n) {
        if(n == 0)return 1;
        int num = Math.abs(n);
        double res = solve(x,num);
        if(n<0){
            return 1/res;
        }
        return res;
    }
}
