class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();

        // Existing count of active sections
        int activeCount = count(s.begin(), s.end(), '1');

        vector<int> inactiveBlock;

        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int start = i;
                while (i < n && s[i] == '0')
                    i++;

                inactiveBlock.push_back(i - start);
            } else {
                i++;
            }
        }

        int maxPairSum = 0;

        for (int j = 1; j < inactiveBlock.size(); j++) {
            maxPairSum = max(maxPairSum,
                             inactiveBlock[j] + inactiveBlock[j - 1]);
        }

        return activeCount + maxPairSum;
    }
};