// https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution {
    public int findKthLargest(int[] nums, int k) {
        return sol3(nums, k);
    }
    
    private int sol1(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        for(int n: nums) {
            pq.offer(n);
        }
        int ret=-1;
        if(pq.size()>=k) {
            for(int i=0;i<k;i++) {
                ret = pq.poll();
            }
        }
        return ret;
    }
    
    private int sol2(int[] nums, int k) {
        Arrays.sort(nums);
        return nums[nums.length - k];
    }
    
    private int sol3(int[] nums, int k) {
        return kthLargestSub(nums, k, 0, nums.length-1);
    }
    
    private int kthLargestSub(int[] arr, int k, int l, int r) {
        if(l<=r) {  // equal is required if only 1 element is in the array
            int p = partition(arr, l, r);
            if(p==arr.length - k) {
                return arr[p];
            } else if(p<arr.length-k) {
                return kthLargestSub(arr, k, p+1, r);
            } else {
                return kthLargestSub(arr, k, l, p-1);
            }
        }
        return -1;
    }

    private int partition(int[] arr, int l, int r) {
        int pivot = arr[r];
        int sidx = l;
        while(l<r) {
            if(arr[l]<pivot) {
                swap(arr, sidx, l);
                sidx++;
            }
            l++;
        }
        swap(arr, sidx, r);
        return sidx;
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}

