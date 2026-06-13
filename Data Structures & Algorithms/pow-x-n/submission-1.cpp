class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)return 1;
        double num= x;
        bool check = false ;
        if(n<0){
            check = true;
            n = n * (-1);
        }
        for(int i =1;i<n;i++){
            x = num*x;
        }
        if(check == true){
            return (double)1/x;
        }
        return x;
    }
};
