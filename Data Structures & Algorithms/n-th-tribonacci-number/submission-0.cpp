class Solution {
public:
    int tribonacci(int n) {
        int t0 = 0;
       int t1 = 1;
        int t2 = 1;
        int ta;
        if(n==0){
            return 0;
        }else if(n>=1 && n<=2){
            return 1;
        }else{
        for(int i = 3;i<=n;i++){
            ta = t0 + t1 + t2;
            t0 = t1;
            t1= t2;
            t2 = ta;
        }
        }

        return ta;
    }
};