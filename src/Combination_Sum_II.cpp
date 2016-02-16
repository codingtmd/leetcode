class Solution {
public:
	vector<vector<int> > combinationSum2(
	    vector<int> &num, int target)
	{
		vector<vector<int> > result;
		vector<int> solution;
		int sum = 0;
		std::sort(num.begin(), num.end());
		GetCombinations(num, sum, 0, target, solution, result);
		return result;
	}

	void GetCombinations(
	    vector<int>& candidates,
	    int& sum,
	    int level,
	    int target,
	    vector<int>& solution,
	    vector<vector<int> >& result)
	{
		if (sum > target) return;
		if (sum == target)
		{
			result.push_back(solution);
			return;
		}
		for (int i = level; i < candidates.size(); i++)
		{
			sum += candidates[i];
			solution.push_back(candidates[i]);
			GetCombinations(
			    candidates, sum, i + 1, target, solution, result);
			solution.pop_back();
			sum -= candidates[i];
			while ( i < candidates.size() - 1
			        && candidates[i] == candidates[i + 1])
				i++;
		}
	}
};