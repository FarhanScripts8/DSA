class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        // If the array has 0 or 1 element, it's already unique.
        if (nums.size() <= 1) return nums.size();

        int left = 1;  // position where next unique element will go

        for (int right = 1; right < nums.size(); ++right) {
            // Check if current value is a new unique value
            if (nums[right] != nums[right - 1]) {
                nums[left] = nums[right];  // place it at 'left'
                ++left;                    // move left to next slot
            }
        }

        // 'left' is the number of unique elements
        return left;
    }
};