class Solution {
public:
    void solve(vector<string>&ans,string &s,int open,int closen,int n){
        if(open == closen && open == n){
            ans.push_back(s);
            return;
        }

        if(open<n){
            s+='(';
            solve(ans,s,open+1,closen,n);
            s.pop_back();
        }
         if(closen<open){
            s+=')';
            solve(ans,s,open,closen+1,n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int open = 0;
        int closen = 0;
        vector<string>ans;
        string s;

        solve(ans,s,open,closen,n);

        return ans;
    }
};
