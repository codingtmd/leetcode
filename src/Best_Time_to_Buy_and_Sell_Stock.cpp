class Solution {
public:
	int maxProfit(vector<int>&prices) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int minV = INT_MAX; int max = 0;
		int diff = 0;
		for (int i = 0; i < prices.size(); i++)
		{
			if (prices[i] < minV) minV = prices[i];
			diff = prices[i] - minV;
			if (max < diff)
				max = diff;
		}
		return max;
	}
};