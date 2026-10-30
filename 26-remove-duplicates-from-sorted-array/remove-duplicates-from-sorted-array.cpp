class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 2 pointer approach
        int n = nums.size();
    
        if (n <= 1) return n;

        int i = 0, j =1;

        while(j<n){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
            j++; // to find unique elements
        }

        
        return i+1;
    }
};