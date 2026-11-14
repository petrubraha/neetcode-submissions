class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), maxLen = 0, l = 0, r = 0;
        unordered_set<char> seen;
        for (int i = 0; i < n; ++i) {
            char chr = s[i];
            while (seen.find(chr) != seen.end()) {
                seen.erase(s[l++]);
            }
            r++;
            maxLen = max(maxLen, r - l);
            seen.insert(chr);
        }
        return maxLen;
    }
};
