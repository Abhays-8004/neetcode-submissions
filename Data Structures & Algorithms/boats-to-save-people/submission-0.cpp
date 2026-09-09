class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i =0;
        int  j = people.size() -1;
        int k = 0;
        while(i<=j){
            int tw = people[i]+people[j];
            if(tw>limit){
                j--;
            }else{
                i++;
                j--;
            }
            k++;
        }

        return k;
    }
};