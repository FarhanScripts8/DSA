class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth = 0;
        int ans = 0;

        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '(') {
                depth++;
            } else {
                if (s[i - 1] == '(') {
                    // Found "()" at current depth
                    ans += 1 << (depth - 1);
                }
                depth--;
            }
        }

        return ans;
    }
};