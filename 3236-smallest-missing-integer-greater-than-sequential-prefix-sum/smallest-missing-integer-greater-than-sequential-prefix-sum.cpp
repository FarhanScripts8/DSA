class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // Step 1: Find longest sequential prefix sum
        int sum = nums[0];
        int i = 1;
        
        while (i < nums.size() && nums[i] == nums[i-1] + 1) {
            sum += nums[i];
            i++;
        }
        
        // Step 2: Create a set for O(1) lookup
        unordered_set<int> present(nums.begin(), nums.end());
        
        // Step 3: Find smallest missing integer >= sum
        int x = sum;
        while (present.count(x)) {
            x++;
        }
        
        return x;
    }
};