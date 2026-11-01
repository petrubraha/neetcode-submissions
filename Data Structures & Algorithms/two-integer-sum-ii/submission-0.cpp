class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size(), i = 0, j = n - 1;
        while (i < j) {
            while (numbers[i] + numbers[j] > target) {
                j--;
            }
            while (numbers[i] + numbers[j] < target) {
                i++;
            }
            if (numbers[i] + numbers[j] == target) {
                return {i + 1, j + 1};
            }
        }
        return {-1, -1};
    }
};
