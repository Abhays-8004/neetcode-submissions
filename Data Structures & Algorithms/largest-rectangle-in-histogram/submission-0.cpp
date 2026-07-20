class Solution {
public:
    void rightSmallervalue(vector<int>& heights,vector<int>& rsv,int n){
        stack<int>st;
        

        for(int i = n-1;i>=0;i--){
            while(st.size()>0 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            rsv[i] =st.empty() ?n: st.top();
            st.push(i);
        }
    }

   void leftSmallerValue(vector<int>& heights,vector<int>& lsv,int n){
        stack<int>st;
        

        for(int i = 0;i<n;i++){
            while(st.size()>0 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            lsv[i] = st.empty() ?-1: st.top();
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
         int n = heights.size();
         int ans = 0;
         vector<int>lsv(n,0);
         vector<int>rsv(n,0);

         leftSmallerValue(heights,lsv,n);
         rightSmallervalue(heights,rsv,n);

         for(int i = 0;i<n;i++){
            ans = max(ans,heights[i]*(rsv[i]-lsv[i]-1));
         }

         return ans;
    }
};
