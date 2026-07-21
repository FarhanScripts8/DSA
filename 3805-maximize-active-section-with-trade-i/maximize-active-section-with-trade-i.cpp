class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int totalOnes = 0;
        for(char c : s)
            if(c == '1')
                totalOnes++;

        string t = "1" + s + "1";

        vector<pair<char,int>> seg;

        for(char c : t){
            if(seg.empty() || seg.back().first != c)
                seg.push_back({c,1});
            else
                seg.back().second++;
        }

        int bestGain = 0;

        for(int i = 1; i + 1 < seg.size(); i++){
            if(seg[i].first == '1' &&
               seg[i-1].first == '0' &&
               seg[i+1].first == '0'){
                bestGain = max(bestGain,
                               seg[i-1].second + seg[i+1].second);
            }
        }

        return totalOnes + bestGain;
    }
};