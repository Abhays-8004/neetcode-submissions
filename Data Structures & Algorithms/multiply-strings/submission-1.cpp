class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.length();
        int m = num2.length();

        long long  n1 = 0;
        long long n2 = 0;
        int digits = 1;
        for(int i = n-1;i>= 0;i--){
            int x = num1[i] - '0';
            n1 = n1 + x*digits;
            digits = digits*10;
        }
        digits = 1;
        for(int i = m-1;i>= 0;i--){
            int x = num2[i] - '0';
            n2 = n2 + x*digits;
            digits = digits*10;
        }
        cout<<n1<<" "<<n2<<" ";
        long long  result = n1 * n2;
        cout<<result<<" ";
        if(result ==  0){
            return "0";
        }
        string ans ="";
        while(result != 0){
            int digit = result % 10;
            result = result / 10;
            ans.push_back('0'+ digit); 
        }
        cout<<ans;
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
