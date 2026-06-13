class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")return "0";
        int n = num1.length();
        int m = num2.length();
        
        vector<int>result(n+m,0);

        for(int i = m-1;i>=0;i--){
            int x = num2[i] - '0';
            for(int j= n-1;j>=0;j--){
                int y = num1[j] - '0';
                int mul = x*y;
                int sum = result[i+j+1] + mul;
                result[i+j+1] = (sum)%10;
                result[i+j] += (sum)/10;
            }
        }

        string ans = "";
        int i =0;
        while(i<result.size()&& result[i] == 0){
            i++;
        }
        while(i<result.size()){
            ans.push_back('0' + result[i]);
            i++;
        }

        // reverse(ans.begin(),ans.end());

       
        return ans.empty() ? "0" : ans;
    }
};
