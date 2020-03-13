//https://leetcode.com/problems/3sum/
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        if(nums==null || nums.length<3){
            return null;
        }

        int target = 0;
        Set<List<Integer>> noDupSet = new HashSet<>();
        Arrays.sort(nums);
        for(int i=0;i< nums.length-1; i++){
            int a = nums[i];
            int s = i+1;
            int e = nums.length-1;
            while(s<e) {
                int b = nums[s];
                int c = nums[e];
                int sum = a+b+c;
                if(sum>target) {
                    e--;
                } else if(sum<target) {
                    s++;
                } else {
                    List<Integer> targetSet = new ArrayList<>();
                    targetSet.add(a);
                    targetSet.add(b);
                    targetSet.add(c);
                    noDupSet.add(targetSet);   
                    s++;
                    e--;
                }
            }
        }
        return new ArrayList<List<Integer>>(noDupSet);
     }
}

