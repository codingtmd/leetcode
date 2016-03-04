class Solution {
public:
    int singleNumber(int A[], int n) {
        int left = A[0];
        for (int i = 1; i < n; i++)
        {
            left = left ^ A[i];
        }
        return left;
    }
};