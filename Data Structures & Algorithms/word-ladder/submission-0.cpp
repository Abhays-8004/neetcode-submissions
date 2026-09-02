class Solution {
public:
    bool checkMatch(string w1,string w2){
        
        int count = 0;
        int n = w1.size();
        for(int i = 0;i<n;i++){
            if(w1[i]!=w2[i]){
                count++;
            }
        }
        return count <=1?true:false;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>>adj;
        unordered_map<string,bool>visited;
        int n = wordList.size();
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                if(checkMatch(wordList[i],wordList[j])){
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
                visited[wordList[j]] = false;
            }
        }
        visited[wordList[0]] = false;

        queue<string>q;
        int ans = 0;
        
        for(int i = 0;i<n;i++){
            if(checkMatch(beginWord,wordList[i])){
                q.push(wordList[i]);
            }
        }

        while(!q.empty()){
            ans++;
            int s = q.size();
            for(int i = 0;i<s;i++){
                string t = q.front();
                q.pop();
                if(t == endWord)return ans+1;
                for(string v:adj[t]){
                    if(!visited[v]){
                        q.push(v);
                        visited[v] = true;
                    }
                }
            }
        }

        return 0;
        
    }
};
