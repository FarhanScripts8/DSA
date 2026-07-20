class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==0) return; 
        //{1,2,3} => (k=3) -> {3,2,1} {2,3,1} {1,2,3}
        //therefore at k = 4 {3,2,1}
        
        k = k % n;
        
        auto reverse = [&](int i, int j) {
            while(i<j){
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        };

        reverse(0, n-1);
        reverse(0, k-1);
        reverse(k, n-1);
              
    }
};