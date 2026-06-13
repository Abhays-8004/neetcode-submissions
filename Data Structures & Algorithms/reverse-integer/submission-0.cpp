class Solution {
public:
    int reverse(int x) {
        if(x>=INT_MAX || x<=INT_MIN){
            return 0;
        }
        long long res = 0;
        while(x!=0){
            int digit = x%10;
            x = x/10;
            if(res>INT_MAX){
                return 0;
            }
            if(res<INT_MIN){
                return 0;
            }
            res = res*10 + digit;
        }

        if(res>INT_MAX || res<INT_MIN){
            return 0;
        }

        return (int)res;

    }
};
