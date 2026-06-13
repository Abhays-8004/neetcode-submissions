class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int num = 0;
        int n = digits.size();
        num = digits[n-1] + 1;
        stack<int>s;
        s.push(num%10);
        carry = num/10;

        for(int i = n-2;i>= 0;i--){
            num = digits[i] + carry;
            s.push(num%10);
            carry = num/10;
        }
        if(carry == 1){
            s.push(carry);
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
