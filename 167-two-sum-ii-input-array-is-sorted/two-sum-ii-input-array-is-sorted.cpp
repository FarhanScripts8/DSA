class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        int i=0;
        int j=(nums.size()-1);

        while(i<j){
            int sum = nums[i]+nums[j]; 
            if (sum == tar){
                return {i+1,j+1};
            }else if(sum < tar){
                i++;
            }else{
                j--;
            }
        }
        return {};
        
    }
};