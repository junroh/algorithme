//https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest {
    private final PriorityQueue<Integer> minHeap;
    private final int target;
    public KthLargest(int k, int[] nums) {
        target=k;
        minHeap = new PriorityQueue<Integer>();
        for(int n:nums) {
            add(n);
        }
    }
    
    public int add(int val) {
        minHeap.add(val);
        if (minHeap.size() > target) {
            minHeap.poll();
            
        }
        return minHeap.peek();    
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */

