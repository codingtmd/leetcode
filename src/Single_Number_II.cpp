class Solution {
public:
    int singleNumber(int A[], int n) {
        vector<int> bit(32, 0);

        for (int i = 0; i < n; ++i)
        {
            int k = 1;
            for (int j = 0; j < 32; ++j)
            {
                int rotated;
                if ((rotated = A[i] >> j) == 0) break;
                bit[j] += rotated & k;
            }
        }

        int target = 0;
        for (int i = 0; i < 32; ++i)
        {
            target += (bit[i] % 3 << i);
        }
        return target;
    }
};