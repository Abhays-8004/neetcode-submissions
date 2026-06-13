class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int>map;
        while(n!= 1){
            int sum = 0;
            int num = n;
            while(num!= 0){
                sum += pow(num%10,2);
                num = num/10;
            }

            if(map.count(sum)){
                return false;
                break;
            }

            map[sum] = 1;
            n = sum;

        }

        return true;
    }
};
