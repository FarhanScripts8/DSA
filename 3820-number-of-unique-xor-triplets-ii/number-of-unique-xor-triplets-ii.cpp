class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int maxEl = *max_element(nums.begin(), nums.end());
        
        int T = 1;
        while (T <= maxEl) T <<= 1;   // power of 2 >= maxEl
        
        vector<bool> pairMask(T, false);
        vector<bool> tripletMask(T, false);
        
        // pair XORs
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                pairMask[nums[i] ^ nums[j]] = true;
            }
        }
        
        // use a snapshot so we don't mutate while iterating
        vector<bool> pairSnapshot = pairMask;
        for (int x = 0; x < T; ++x) {
            if (!pairSnapshot[x]) continue;
            for (int v : nums) {
                tripletMask[x ^ v] = true;
            }
        }
        
        int count = 0;
        for (int x = 0; x < T; ++x) {
            if (tripletMask[x]) ++count;
        }
        return count;
    }
};