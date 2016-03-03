class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> result(digits.size(), 0);

        int carryon = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            int digit = digits[i];
            result[i] = (digit + carryon) % 10;
            carryon = (digit + carryon) / 10;
        }

        if (carryon > 0)
        {
            result.insert(result.begin(), carryon);
        }
        return result;
    }
};