class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
    vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
       ans.push_back(intervals[0]);

       for(auto &interval:intervals){
        int start= interval[0];
        int end = interval[1];
        int lastend = ans.back()[1];
        if(start<=lastend){
            ans.back()[1] = max(lastend,end);
        }else{
            ans.push_back({start,end});
        }
       }

        return ans;
    }
};
