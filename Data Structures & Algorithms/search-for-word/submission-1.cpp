class Solution {
   public:
    bool dfs(int i, int j, int idx, vector<vector<char>>& board, string word, int n, int m) {
        if (idx == word.size()) return true;
        if (i >= n || i < 0 || j >= m || j < 0 || board[i][j] != word[idx]) return false;
        char temp = board[i][j];
        board[i][j] = '#';
        bool found = (dfs(i + 1, j, idx + 1, board, word, n, m) ||
                      dfs(i - 1, j, idx + 1, board, word, n, m) ||
                      dfs(i, j + 1, idx + 1, board, word, n, m) ||
                      dfs(i, j - 1, idx + 1, board, word, n, m));
        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, 0, board, word, n, m)) return true;
                }
            }
        }
        return false;
    }
};
