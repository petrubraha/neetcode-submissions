class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> seen;
        for (int i = 0; i < n; ++i) {
            seen[nums[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            int complement = target - nums[i];
            auto it = seen.find(complement);
            if (it == seen.end()) {
                continue;
            }
            int otherIdx = it->second;
            if (otherIdx > i) {
                return {i, otherIdx};
            }
            if (otherIdx < i) {
                return {otherIdx, i};
            }
        }
    }
};
