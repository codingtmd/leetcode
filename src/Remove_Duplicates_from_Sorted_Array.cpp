class Solution {
public:
    int removeDuplicates(vector<int>& A) {
        int n = A.size();
        if (n == 0) return 0;
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[index] == A[i]) // duplicate, skip
            {
                continue;
            }
            index++; // non-duplicate, copy it to second pointer
            A[index] = A[i];
        }
        return index + 1;
    }
};