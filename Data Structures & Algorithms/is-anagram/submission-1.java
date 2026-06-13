class Solution {
    public boolean isAnagram(String s, String t) {
        int n = s.length();
        int m = t.length();
        if(n!= m ){
            return false;
        }
        Map<Character,Integer> hasmap = new HashMap<>();

        for(char c  : t.toCharArray()){
            hasmap.put(c , hasmap.getOrDefault(c,0)+1);
        }

        for(char c:s.toCharArray()){
            if(hasmap.containsKey(c)){
                hasmap.replace(c,hasmap.get(c)-1);
                if(hasmap.get(c)<=0){
                    hasmap.remove(c);
                }
            }else{
                return false;
            }
        }

        return true;
    }
}
