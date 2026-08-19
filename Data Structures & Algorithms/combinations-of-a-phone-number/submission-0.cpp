class Solution {
public:
unordered_map<char,string>map = {
    {'2',"abc"},
    {'3',"def"},
    {'4',"ghi"},
    {'5',"jkl"},
    {'6',"mno"},
    {'7',"pqrs"},
    {'8',"tuv"},
    {'9',"wxyz"}
};
     void solve(int idx,string s,vector<string>&ans,string digits){
        if(idx == digits.size()){
            ans.push_back(s);
            return ;
        }
        string t = map[digits[idx]];
        for(char &v:t){
            s += v;
            solve(idx+1,s,ans,digits);
            s.pop_back();
        }

        return ;
     }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return {};
        }
        vector<string>ans;
        string s = "";
        solve(0,s,ans,digits);

        return ans;

    }
};
