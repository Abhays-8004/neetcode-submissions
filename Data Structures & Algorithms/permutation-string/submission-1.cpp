class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = s1.size();

        unordered_map<string,bool>map;
        int t = s2.size() - l+1;
        for(int i = 0;i<=t;i++){
            string st = s2.substr(i,l);
            map[st] = true;
        }

        s1 = s1+s1;

        for(int i = 0;i<l;i++){
            string  st = s1.substr(i,l);
            
            if(map[st]){
                return true;
            }
            reverse(st.begin(),st.end());
            if(map[st]){
                return true;
            }
        }

        return false;
    }
};
