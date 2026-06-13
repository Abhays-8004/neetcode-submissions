class Solution {
public:
   
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>map;
        vector<vector<string>>ans;

        for(auto & s:strs){
          string f = s;
          sort(f.begin(),f.end());
          map[f].push_back(s);
        }

        for(auto& v:map){
            ans.push_back(v.second);
        }

        return ans;
    }
};
