class Solution {
public:
    bool isAlphanumeric(char c) {
        return
            (c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9');
    }

    bool isEqual(char c1, char c2) {
        if (c1 >= 'A' && c1 <= 'Z') {
            c1 += 32;
        }
        if (c2 >= 'A' && c2 <= 'Z') {
            c2 += 32;
        }
        return c1 == c2;
    }

    bool isPalindrome(string s) {
        int n = s.size();
        for (int frst = 0, last = n - 1; frst < last; ++frst, --last) {
            while(frst < last && !isAlphanumeric(s[frst])) frst++; 
            while(frst < last && !isAlphanumeric(s[last])) last--; 
            if (frst < last && !isEqual(s[frst], s[last])) {
                return false;
            }
        }
        return true;
    }
};
