class Solution {
public:
	int numDistinct(string S, string T) {
		int match[200];
		if (S.size() < T.size()) return 0;
		match[0] = 1;
		for (int i = 1; i <= T.size(); i++)
			match[i] = 0;
		for (int i = 1; i <= S.size(); i ++)
			for (int j = T.size(); j >= 1; j--)
				if (S[i - 1] == T[j - 1])
					match[j] += match[j - 1];
		return match[T.size()];
	}
};