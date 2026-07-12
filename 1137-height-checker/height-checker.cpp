class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ans = 0;
        vector<int> so = heights;
        sort(so.begin(), so.end());
        for(int i=0; i<so.size(); i++) ans += (so[i] != heights[i]);
        return ans;
    }
};