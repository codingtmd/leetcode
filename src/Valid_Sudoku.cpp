class Solution {
public:

    bool isValidSudoku(vector<vector<char> > &board) {
        if (board.size() == 0) return false;
        int row[9], col[9];
        for (int i = 0; i < 9; i++)
        {
            memset(row, 0, 9 * sizeof(int));
            memset(col, 0, 9 * sizeof(int));
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (row[board[i][j] - 49] == 1)
                        return false;
                    row[board[i][j] - 49]++;
                }
                if (board[j][i] != '.')
                {
                    if (col[board[j][i] - 49] == 1)
                        return false;
                    col[board[j][i] - 49]++;
                }
            }
        }
        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                memset(row, 0, 9 * sizeof(int));
                for (int m = 0; m < 3; m++)
                {
                    for (int n = 0; n < 3; n++)
                    {
                        if (board[m + i][n + j] == '.')
                            continue;
                        if (row[board[m + i][n + j] - 49] == 1)
                            return false;
                        row[board[m + i][n + j] - 49]++;
                    }
                }
            }
        }
        return true;
    }
};