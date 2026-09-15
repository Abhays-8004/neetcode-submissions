class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;

        for(int v:asteroids){
            if(st.empty() || v>0){
                st.push(v);
            }else{
                int t = abs(v);
                while(!st.empty() && st.top()>0 && st.top()<t){
                    st.pop();
                }

                if(st.empty() || st.top()<0){
                    st.push(v);
                }else if(st.top() == t){
                    st.pop();
                }
            }
        }

        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};