class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();          // 1 <= n <= 26 [page:1]
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int group = i / 8;        // 0..3
            ans += (group + 1);       // cost for this letter
        }
        return ans;
    }
};