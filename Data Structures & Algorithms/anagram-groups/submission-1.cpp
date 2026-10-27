class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> vec;
        map<vector<int>, int> mapAnagramToSublist;
        int n = strs.size();
        for (int i = 0; i < n; ++i) {
            int m = strs[i].size();
            vector<int> anagram(26, 0);
            for (int j = 0; j < m; ++j) {
                anagram[strs[i][j] - 'a']++;
            }
            if (mapAnagramToSublist.find(anagram) == mapAnagramToSublist.end()) {
                int sublistIdx = vec.size();
                mapAnagramToSublist[anagram] = sublistIdx;
                vec.push_back({strs[i]});
                continue;
            }
            int sublistIdx = mapAnagramToSublist[anagram];
            vec[sublistIdx].push_back(strs[i]);
        }
        return vec;
    }
};
