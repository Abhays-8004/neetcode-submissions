class Solution {
    public int lastStoneWeight(int[] stones) {
         PriorityQueue<Integer> maxheap = new PriorityQueue<>(Collections.reverseOrder());
         for(int i = 0;i<stones.length;i++){
            maxheap.offer(stones[i]);
         }

         while(maxheap.size()>=2){
            int y = maxheap.peek();
            maxheap.poll();
            int x = maxheap.peek();
            maxheap.poll();
            if(x!= y){
                maxheap.offer(y-x);
            }
        }

        if(maxheap.size()>0){
            return maxheap.peek();
        }

        return 0;
    }
}
