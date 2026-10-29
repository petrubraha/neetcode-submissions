class Solution {
    int decode_count(const string& str, int& idx) {
        int n = str.size();
        int count = 0;
        for (; idx < n && str[idx] != SEPARATOR; ++idx) {
            char chr = str[idx] - '0';
            count *= 10;
            count += chr;
        }
        return count;
    }

public:
    static constexpr char SEPARATOR = '_';

    string encode(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) {
            return "";
        }
        string enc;
        for (const string& str : strs) {
            enc += to_string(str.size()) + SEPARATOR + str;
        }
        return enc;
    }

    vector<string> decode(string s) {
        if (s == "") {
            return {};
        }
        int idx = 0;
        const int n = s.size();
        vector<string> result;
        while (idx < n) {
            int ssize = decode_count(s, idx);
            // read the separator
            idx++;
            string subs = s.substr(idx, ssize);
            idx += ssize;
            result.emplace_back(std::move(subs));
        }
        return result;
    }
};