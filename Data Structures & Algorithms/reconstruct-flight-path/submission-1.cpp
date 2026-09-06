class Solution {
public:
   
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string>result;
        unordered_map<string,vector<string>>adj;

        for(auto&ticket:tickets){
            adj[ticket[0]].push_back(ticket[1]);
 
        }

        for(auto &[src,dest]:adj){
            sort(dest.rbegin(),dest.rend());
        }

       stack<string>st;
       st.push("JFK");
       while(!st.empty()){
        string curr = st.top();
        if(!adj[curr].empty()){
            string s = adj[curr].back();
            adj[curr].pop_back();
            st.push(s);
        }else{
            result.push_back(curr);
            st.pop();
        }
       }

       reverse(result.begin(),result.end());

        return result;
    }
};
