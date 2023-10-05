// Date: October 5, 2023
class Solution {
public:
    int get(vector<int>& nums, int i) {
        if(i < 0 || i >= nums.size()) return INT_MIN;
        return nums[i];
    }
    
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size()-1, n = nums.size();
        while (l < r) {
            int mid = l+r >> 1;
            if(get(nums, mid) < get(nums, mid+1)) l = mid+1;
            else r = mid;
        }
        return l;
    }
};
