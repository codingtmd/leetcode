class Solution {
public:
    int removeDuplicates(vector<int>& A) {
        int n = A.size();
        if (n == 0) return 0;
        int occur = 1;
        int index = 0;

        for (int i = 1; i < n; i++)
        {
            if (A[index] == A[i])
            {
                if (occur == 2)
                {
                    continue;
                }
                occur++;
            }
            else
            {
                occur = 1 ;
            }

            A[++index] = A[i];

        }
        return index + 1;
    }
};