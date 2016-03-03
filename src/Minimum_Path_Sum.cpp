class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		int row = grid.size();
		if (row == 0) return 0;
		int col = grid[0].size();
		if (col == 0) return 0;
		vector<int> steps(col, INT_MAX);
		steps[0] = 0;
		for (int i = 0; i < row; i++)
		{
			steps[0] = steps[0] + grid[i][0];
			for (int j = 1; j < col; j++)
			{
				steps[j] = min(steps[j], steps[j - 1]) + grid[i][j];
			}
		}
		return steps[col - 1];
	}
};