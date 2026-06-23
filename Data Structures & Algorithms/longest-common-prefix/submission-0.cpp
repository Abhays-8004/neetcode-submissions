class Solution {
public:
   
    string longestCommonPrefix(vector<string>& strs) {
       int n = strs.size();
       string ans ="";
       sort(strs.begin(),strs.end());
       int m = strs[0].length();
       for(int i =  0;i<m;i++){
        char s = strs[0][i];
        for(int j = 1;j<n;j++){
            if(s  != strs[j][i]){
                s = ' ';
            }
        }
        if (s != ' '){
                ans.push_back(s);
        }else{
            return ans;
        }
            
       }
       
        return ans;
    }
};