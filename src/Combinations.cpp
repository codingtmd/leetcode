class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > result;
		vector<int> solution;
		GetCombine(n, k, 1, solution, result);
		return result;
	}
	void GetCombine(
	    int n,
	    int k,
	    int level,
	    vector<int>& solution,
	    vector<vector<int> >& result)
	{
		if (solution.size() == k)
		{
			result.push_back(solution);
			return;
		}
		for (int i = level; i <= n; i++)
		{
			solution.push_back(i);
			GetCombine(n, k, i + 1, solution, result);
			solution.pop_back();
		}
	}
};