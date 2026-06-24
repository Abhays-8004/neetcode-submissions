class Solution {
public:
    vector<int>length;
    string encode(vector<string>& strs) {
        string str = "";
        for(string s:strs){
            str += s ;
            length.push_back(s.size());
        }

        return str;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string>ans;
        for(int l:length){
            ans.push_back(s.substr(i,l));
            i+= l;
        }

        return ans;
    }
};
