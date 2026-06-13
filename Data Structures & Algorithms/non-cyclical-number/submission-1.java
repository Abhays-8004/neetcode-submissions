class Solution {
    public boolean isHappy(int n) {
                Map<Integer,Integer>map = new HashMap<>();
        while(n!= 1){
            int sum = 0;
            int num = n;
            while(num!= 0){
                sum += (int) Math.pow(num % 10, 2);
                num = num/10;
            }

            if(map.containsKey(sum)){
                return false;
            }

            map.put(sum,1);
            n = sum;

        }

        return true;
    }
}
