class Solution {
public:
    int minimumPushes(string word) {
        // Step 1: count frequencies of letters
        vector<int> cnt(26, 0);
        for (char c : word) {
            cnt[c - 'a']++;
        }

        // Step 2: collect non-zero frequencies
        vector<int> freqs;
        for (int f : cnt) {
            if (f > 0) freqs.push_back(f);
        }

        // Step 3: sort frequencies in descending order
        sort(freqs.begin(), freqs.end(), greater<int>());

        // Step 4: assign costs and compute total
        long long ans = 0;
        for (int i = 0; i < (int)freqs.size(); ++i) {
            int cost = i / 8 + 1;      // 8 keys => 8 positions per cost level
            ans += 1LL * freqs[i] * cost;
        }

        return (int)ans;
    }
};