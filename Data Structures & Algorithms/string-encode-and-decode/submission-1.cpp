class Solution {
    static constexpr char separator = '.';
public:

    string encode(vector<string>& strs) {
        string result;
        result.reserve(strs.size());
        for (string& str : strs) {
            result += to_string(str.size()) + separator + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        int i = 0, n = s.size();
        vector<string> result;
        result.reserve(n / 2);
        while (i < n) {
            // read count
            int j = i + 1;
            while (s[j] != separator) j++;
            int count = stoi(s.substr(i, j));
            i += j - i;
            // read separator
            i++;
            // read string
            string substr = s.substr(i, count);
            i += count;
            result.push_back(move(substr));
        }
        return result;
    }
};
