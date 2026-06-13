class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char,int>map;
        int i = 0;
        int maxf = 0;
        int ans = 0;
        for(int j = 0;j<n;j++){
            map[s[j]]++;
            maxf =max(maxf,map[s[j]]);

            while((j-i+1)-maxf >k){
                map[s[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);
        }

        return ans;
    }
};
