class Solution {
public:
    int trap(int A[], int n) {
        if (n < 2) return 0;
        vector<int> lmax(n, 0);
        vector<int> rmax(n, 0);

        int maxV = A[0];
        lmax[0] = A[0];
        for (int i = 1; i < n; i++)
        {
            maxV = std::max(maxV, A[i - 1]);
            lmax[i] = maxV;
        }

        maxV = A[n - 1];
        rmax[n - 1] = A[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            maxV = std::max(maxV, A[i + 1]);
            rmax[i] = maxV;
        }

        int total = 0;
        for (int i = 0; i < n; i++)
        {
            int diff = std::min(lmax[i], rmax[i]) - A[i];
            if (diff > 0)
                total += diff;
        }

        return total;
    }
};