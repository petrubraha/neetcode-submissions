class Solution {
public:
    // returns false if already existent
    bool insertSet(unordered_set<char>& s, char c) {
        if (c == '.') {
            return true;
        }
        if (s.find(c) != s.end()) {
            return false;
        }
        s.insert(c);
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        array<unordered_set<char>, 9> columnSets, squareSets;
        for (int i = 0; i < n; ++i) {
            unordered_set<char> rowSet;
            for (int j = 0; j < n; ++j) {
                char c = board[i][j];
                int squareIndex = (i / 3) * 3 + j / 3;
                if (!insertSet(columnSets[j], c) || !insertSet(squareSets[squareIndex], c) || !insertSet(rowSet, c)) {
                    return false;
                }
            }
        }
        return true;
    }
};
