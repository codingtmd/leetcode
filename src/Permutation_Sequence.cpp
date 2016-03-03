class Solution {
public:

    string getPermutation(int n, int k) {
        vector<int> nums(n);
        int permCount = 1;
        for (int i = 0; i < n; i++)
        {
            nums[i] = i + 1;
            permCount *= (i + 1);
        }
        // change K from (1,n) to (0, n-1) to accord to index
        k--;
        string targetNum;
        for (int i = 0; i < n; i++)
        {
            permCount = permCount / (n - i);
            int choosed = k / permCount;
            targetNum.push_back(nums[choosed] + '0');
            //restruct nums since one num has been picked
            for (int j = choosed; j < n - i; j++)
            {
                nums[j] = nums[j + 1];
            }
            k = k % permCount;
        }
        return targetNum;
    }
};