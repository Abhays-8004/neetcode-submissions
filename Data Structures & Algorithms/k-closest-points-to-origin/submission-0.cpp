class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float, pair<int,int>>> pq;
         int n = points.size();
        for(int i = 0;i<n;i++){
            float  dis = sqrt(pow(points[i][0],2) + pow(points[i][1],2));

            pq.push({dis,{points[i][0],points[i][1]}});

            while(!pq.empty() && pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>>result;
        while(!pq.empty()){
            result.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }

        return result;
    }
};
