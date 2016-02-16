class Solution {
public:
	int climbStairs(int n) {
		int fn_2 = 1, fn_1 = 2;
		if (n == 1) return fn_2;
		if (n == 2) return fn_1;
		int fn;
		for (int i = 3; i <= n; i++)
		{
			fn = fn_2 + fn_1;
			fn_2 = fn_1;
			fn_1 = fn;
		}
		return fn;
	}
};