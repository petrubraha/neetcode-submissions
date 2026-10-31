class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> vals;
        for (int i = 0; i < n; ++i) {
            vals.insert(nums[i]);
        }
        int maxLen = 0;
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            if (vals.find(num - 1) != vals.end()) {
                continue;
            }
            int len = 1;
            while (vals.find(++num) != vals.end()) {
                len++;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};
