class Solution {
public:
    string minWindow(string S, string T) {
        if (S.size() == 0) return "";
        if (S.size() < T.size()) return "";
        int appearCount[256];
        int expectCount[256];
        memset(appearCount, 0, 256 * sizeof(appearCount[0]));
        memset(expectCount, 0, 256 * sizeof(appearCount[0]));
        for (int i = 0; i < T.size(); i++)
        {
            expectCount[T[i]]++;
        }
        int minV = INT_MAX, min_start = 0;
        int wid_start = 0;
        int appeared = 0;
        for (int wid_end = 0; wid_end < S.size(); wid_end++)
        {
            if (expectCount[S[wid_end]] > 0) //his char is a part of T
            {
                appearCount[S[wid_end]]++;
                if (appearCount[S[wid_end]] <= expectCount[S[wid_end]])
                    appeared ++;
            }
            if (appeared == T.size())
            {
                while (appearCount[S[wid_start]] > expectCount[S[wid_start]]
                        || expectCount[S[wid_start]] == 0)
                {
                    appearCount[S[wid_start]]--;
                    wid_start ++;
                }
                if (minV > (wid_end - wid_start + 1))
                {
                    minV = wid_end - wid_start + 1;
                    min_start = wid_start;
                }
            }
        }
        if (minV == INT_MAX) return "";
        return S.substr(min_start, minV);
    }
};