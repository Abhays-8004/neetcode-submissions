class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.size();
        int start_i = 0;
        int minwindow = INT_MAX;
        int i = 0;int j = 0;
        int countreq = t.size();
        unordered_map<char,int>map;
        for(char &c:t){
            map[c]++;
        }
        while(j<n){
            if(map[s[j]] >0){
                countreq--;
            }
                map[s[j]]--;
                while(countreq == 0){
                    int currwindow = j-i+1;
                    if(minwindow > currwindow){
                        minwindow = currwindow;
                        start_i = i;
                    }
                    map[s[i]]++;
                    if(map[s[i]]> 0){
                        countreq++;
                    }
                    i++;
                }
            
            j++;
        }


        return  minwindow == INT_MAX ? "" : s.substr(start_i,minwindow);
    }
};
