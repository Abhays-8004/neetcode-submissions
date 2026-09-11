class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        if(n == k)return arr;

        int i = 0;int j = n-1;
        while(j-i+1 != k){
            if(abs(arr[i] - x)>abs(arr[j] - x)){
                i++;
            }else{
                j--;
            }
        }
        vector<int>ans;

        while(i<=j){
            ans.push_back(arr[i]);
            i++;
        }

        return ans;
    }
};