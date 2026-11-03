class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), len = 0;
        unordered_set<int> seen(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            if (seen.find(nums[i] - 1) != seen.end()) {
                continue;
            }
            int num = nums[i] + 1, current = 1;
            while (seen.find(num++) != seen.end()) {
                current++;
            }
            len = max(len, current);
        }
        return len;
    }
};
