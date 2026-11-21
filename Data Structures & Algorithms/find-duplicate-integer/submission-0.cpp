class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        short n = nums.size() - 1;
        short bits = 16;
        short result = 0;
        for (short i = 0; i < bits; ++i) {
            short mask = 1 << i;
            short observed = 0, count = 0;
            for (short num = 1; num < n + 1; ++num) {
                if (mask & num) {
                    count++;
                }
            }
            for (short j = 0; j < n + 1; ++j) {
                if (mask & nums[j]) {
                    observed++;
                }
            }
            if (observed > count) {
                result |= mask;
            }
        }
        return result;
    }
};
