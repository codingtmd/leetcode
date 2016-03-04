class Solution {
public:
    void sortColors(vector<int>& A) {
        int redSt = 0, bluSt = A.size() - 1;
        int i = 0;
        while (i < bluSt + 1)
        {
            if (A[i] == 0)
            {
                std::swap(A[i], A[redSt]);
                redSt++;
                i++;   //move scan index together with red index
                continue;
            }
            if (A[i] == 2)
            {
                std::swap(A[i], A[bluSt]);
                bluSt--;   //only move blue index
                continue;
            }
            i++;
        }
    }
};