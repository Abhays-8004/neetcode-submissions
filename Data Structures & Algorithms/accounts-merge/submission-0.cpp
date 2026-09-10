class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x]= find(parent[x]);
    }

    void unionset(int x,int y){
        int parentx = find(x);
        int parenty = find(y);

        if(parentx == parenty){
            return ;
        }
        else if(rank[parentx]>rank[parenty]){
            parent[parenty] = parentx;
        }else if(rank[parentx]<rank[parenty]){
            parent[parentx] = parenty;
        }else{
            parent[parenty] = parentx;
            rank[parentx]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        rank.resize(n,0);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }

        unordered_map<string,int>emailtoacc;

        for(int i = 0;i<n;i++){
            for(int j = 1;j<accounts[i].size();j++){
                string v = accounts[i][j];
                if(emailtoacc.count(v)){
                    unionset(i,emailtoacc[v]);
                }else{
                    emailtoacc[v]= i;
                }
            }
        }

        unordered_map<int,vector<string>>emailgroup;

        for(auto & [email,acc]:emailtoacc){
            int parent = find(acc);
            emailgroup[parent].push_back(email);
        }

       vector<vector<string>> res;
        for (auto& [accId, emails] : emailgroup) {
            sort(emails.begin(), emails.end());
            vector<string> merged;
            merged.push_back(accounts[accId][0]);
            merged.insert(merged.end(), emails.begin(), emails.end());
            res.push_back(merged);
        }

        return res;



    }
};