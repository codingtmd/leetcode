class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		std::sort(num.begin(), num.end());
		vector<vector<int>> result;
		for (int i = 0 ; i < num.size() ; i++ )
		{
			int target = 0 - num[i];
			int start = i + 1, end = num.size() - 1;
			while (start < end)
			{
				int sum = num[start] + num[end];
				if (sum == target)
				{
					vector<int> oneSolution;
					oneSolution.push_back(num[i]);
					oneSolution.push_back(num[start]);
					oneSolution.push_back(num[end]);
					result.push_back(oneSolution);
					start++;
					end--;
					while (start < num.size() && num[start] == num[start - 1]) start++;
					while (end > 0 && num[end] == num[end + 1]) end--;
				}

				if (sum < target)
				{
					start++;
				}

				if (sum > target)
				{
					end--;
				}
			}

			while (i < num.size() - 1 && num[i] == num[i + 1]) i++;
		}
		return result;
	}
};