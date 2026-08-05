class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Build directed graph
        vector<vector<int>> graph(n);
        for (const auto& e : invocations) {
            graph[e[0]].push_back(e[1]);
        }

        // Step 1: BFS from k to find all suspicious methods
        vector<bool> suspicious(n, false);
        queue<int> q;
        q.push(k);
        suspicious[k] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : graph[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = true;
                    q.push(v);
                }
            }
        }

        // Step 2: Check if any non-suspicious method invokes a suspicious one
        for (const auto& e : invocations) {
            int u = e[0], v = e[1];
            if (!suspicious[u] && suspicious[v]) {
                // Cannot remove; return all methods
                vector<int> all(n);
                iota(all.begin(), all.end(), 0);
                return all;
            }
        }

        // Step 3: Return non-suspicious methods
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (!suspicious[i]) ans.push_back(i);
        }
        return ans;
    }
};