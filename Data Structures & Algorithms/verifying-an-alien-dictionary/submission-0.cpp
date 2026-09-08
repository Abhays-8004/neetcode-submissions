class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>maporder;
        for(int i = 0;i<26;i++){
            maporder[order[i]] = i;
        }

        for(int i = 1;i<words.size();i++){
            string w1 = words[i-1];
            string w2 = words[i];
            int j  =0;
            while(j<w1.size() && j<w2.size()){
                if(maporder[w1[j]]>maporder[w2[j]]){
                    return false;
                }
                else if(maporder[w1[j]]<maporder[w2[j]]){
                    break;
                }else{
                    j++;
                }
            }
            if(j== w2.size()&& w2.size()<w1.size())return false;
        }

        return true;
    }
};