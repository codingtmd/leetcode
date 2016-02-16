class Solution {
public:
	int numDecodings(string s) {
		if (s.empty() || s[0] == '0') return 0;
		if (s.size() == 1) return check(s[0]);
		int fn = 0, fn_1 = 0, fn_2 = 1;
		fn_1 = (check(s[0]) * check(s[1])) + check(s[0], s[1]);
		for (int i = 2; i < s.size(); i++)
		{
			if (check(s[i])) fn += fn_1;
			if (check(s[i - 1], s[i])) fn += fn_2;
			if (fn == 0)
				return 0;
			fn_2 = fn_1;
			fn_1 = fn;
			fn = 0;
		}
		return fn_1;
	}

	int check(char one)
	{
		return (one != '0') ? 1 : 0;
	}
	
	int check(char one, char two)
	{
		return (one == '1' || (one == '2' && two <= '6')) ? 1 : 0;
	}

};