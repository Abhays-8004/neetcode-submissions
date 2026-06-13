class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>s;
       
        int n = temperatures.size();
        vector<int>ans(n);
        for(int  i = n-1;i>=0;i--){
            while(!s.empty() && temperatures[i]>=temperatures[s.top()]){
                s.pop();
            }

            ans[i] = s.empty() == true ? 0:s.top()- i;
            s.push(i);
        }

        return ans;
    }
};
