class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int cost1 = 0;
        int cost2 = 0;
        int n = cost.length;
        if(n == 2)return Math.min(cost[0],cost[1]);

        for(int i = 2;i<=n;i++){
            cost1 = Math.min(cost1+cost[i-2],cost2+cost[i-1]);
            int tmp = cost1;
            cost1  = cost2;
            cost2 = tmp;
            
        }

        return cost2;
    }
}
