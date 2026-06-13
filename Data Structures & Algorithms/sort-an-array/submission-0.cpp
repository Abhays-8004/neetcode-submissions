class Solution {
public:
    void merge(vector<int>& nums,int s,int mid,int e){
        
        vector<int>newarr;
        int i = s;
        int j = mid+1;
        
        while(i<=mid && j<=e){
            if(nums[i]<=nums[j]){
                newarr.push_back(nums[i]);
                i++;
            }else{
                newarr.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            newarr.push_back(nums[i]);
            i++;
        }
        while(j<=e){
            newarr.push_back(nums[j]);
            j++;
        }

        for(int i = 0;i<newarr.size();i++){
            nums[s] = newarr[i];
            s++;
        }
    }
    void mergesort(vector<int>&nums,int s ,int e){
        
        if(s == e){
            return ;
        }

        int mid = s+(e-s)/2;

        mergesort(nums,s,mid);
        mergesort(nums,mid+1,e);
        merge(nums,s,mid,e);
        return;
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);

        return nums;
    }
};