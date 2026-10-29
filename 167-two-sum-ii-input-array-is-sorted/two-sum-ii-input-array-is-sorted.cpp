class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //two pointer's approach
        int st=0, end = nums.size()-1;
        int currsum = 0;
        //vector<int> ans;

        while(st<end){
            int currsum = nums[st]+nums[end]; 
            if (currsum == target){
                return {st + 1, end + 1};
            }else if(currsum > target){
                end--;
            }else{
                st++;
            }
        }
        return {};
        
    }
};