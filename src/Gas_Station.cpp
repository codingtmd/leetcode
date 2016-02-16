class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		vector<int> diff(gas.size());
		for (int i = 0; i < gas.size(); ++i)
		{
			diff[i] = gas[i] - cost[i];
		}
		int leftGas = 0, sum = 0, startnode = 0;
		for (int i = 0; i < gas.size(); ++i)
		{
			leftGas += diff[i];
			sum += diff[i];
			if (sum < 0) //if less than 0, skip it
			{
				startnode = i + 1;
				sum = 0;
			}
		}
		if (leftGas < 0)
			return -1;
		else
			return startnode;
	}
};