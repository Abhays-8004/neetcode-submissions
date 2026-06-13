class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i =0;
        int j = 0;
        unordered_map<char,int>map;
        int ans =0;
        while(j<n){
            if(map.count(s[j])){
                while(i<n && map.count(s[j])){
                    map[s[i]]--;
                    if(map[s[i]] == 0){
                        map.erase(s[i]);
                    }
                    i++;
                }
            }

            map[s[j]]++;
            ans = max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};
