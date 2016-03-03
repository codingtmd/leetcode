class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        result.resize(rowIndex + 2);
        for (int i = 0; i < rowIndex + 2; i++)
            result[i] = 0;
        result[1] = 1;
        for (int i = 0; i < rowIndex; i++)
        {
            //from right to left. avoid duplicate add
            for (int j = rowIndex + 1; j > 0; j--)
            {
                result[j] = result[j - 1] + result[j];
            }
        }
        result.erase(result.begin());
        return result;
    }
};