class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length ==0) return 0;

        HashSet<Integer> numset = new HashSet<>();

        for(int num : nums){
            numset.add(num);
        }
        int lcs = 0;
        for(int num : numset){
            if(numset.contains(num-1)) continue;
            else{
                int cs = 1;
                int currnum = num;
                
                while(numset.contains(currnum+1)){
                    currnum++;
                    cs++;
                }
                lcs = Math.max(lcs,cs);
            }
        }
        return lcs;
    }
}
