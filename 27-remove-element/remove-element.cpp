class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == val) {
                nums.erase(nums.begin() + i); // erase at i, do not increment i
            } else {
                i++; // only move forward if we didn't erase
            }
        }
        return nums.size();
    }
};