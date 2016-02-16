class Solution {
public:
	int minDistance(string word1, string word2) {
		if (word1.size() < word2.size())
			word1.swap(word2);
		int * matchUp = new int[20000];
		int* matchDown = new int[20000];
		for (int i = 0; i <= word2.size(); i++)
		{
			matchUp[i] = 0;
			matchDown[i] = i;
		}
		for (int i = 1; i <= word1.size(); i++)
		{
			matchUp[0] = i;
			for (int j = 1; j <= word2.size(); j++)
			{
				if (word1[i - 1] == word2[j - 1])
				{
					matchUp[j] = matchDown[j - 1];
				}
				else
				{
					matchUp[j] = min(matchDown[j], matchDown[j - 1]);
					matchUp[j] = min(matchUp[j], matchUp[j - 1]) + 1;
				}
			}
			int* temp = matchUp;
			matchUp = matchDown;
			matchDown = temp;
		}
		return matchDown[word2.size()];
	}
};