class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target == "0000")return 0;
        unordered_map<string,bool>visited;
        for(string s:deadends){
            visited[s] = true;
        }
        if(visited.count("0000"))return -1;

        int ans = 0;
        queue<string>q;
        q.push("0000");
        visited["0000"] = true;

        while(!q.empty()){
            int n = q.size();
            ans++;
            for(int i = 0;i<n;i++){
                string  lock = q.front();
                q.pop();
                for(int j = 0;j<4;j++){
                    for(int move:{1,-1}){
                        string nextlock =lock;
                      nextlock[j] = (nextlock[j] - '0' + move + 10) % 10 + '0';
                      if(visited.count(nextlock))continue;
                      if(nextlock == target)return ans;
                      q.push(nextlock);
                      visited[nextlock] = true;
                    }
                }
            }
        }
        return -1;
    }
};