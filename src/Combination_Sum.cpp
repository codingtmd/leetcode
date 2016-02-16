class Solution {
public:
	vector<vector<int> > combinationSum(
	    vector<int> &candidates, int target)
	{
		vector<vector<int> > result;
		vector<int> solution;
		int sum = 0;
		std::sort(candidates.begin(), candidates.end());
		GetCombinations(
		    candidates, sum, 0, target, solution, result);
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
			    candidates, sum, i, target, solution, result);
			solution.pop_back(); // do not miss cleaning the num
			sum -= candidates[i];
		}
	}
};