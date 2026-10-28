// 11:46
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        freq.reserve(n);
        for (auto num : nums) {
            freq[num]++;
        }
        int maxFreq = -1;
        unordered_map<int, vector<int>> freqToNums;
        freqToNums.reserve(freq.size());
        for (auto numFreqPair : freq) {
            freqToNums[numFreqPair.second].emplace_back(numFreqPair.first);
            maxFreq = max(numFreqPair.second, maxFreq);
        }
        vector<int> result;
        result.reserve(k);
        for (int f = maxFreq; k > 0 && f >= 0; --f) {
            vector<int>& vals = freqToNums[f];
            for (auto val : vals) {
                if (k <= 0) {
                    break;
                }
                result.emplace_back(val);
                k--;
            }
        }
        return result;
    }
};
