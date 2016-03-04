class Solution {
public:
    vector<int> searchRange(vector<int>& A, int target) {
        int n = A.size();
        vector<int> result;
        result.push_back(-1);
        result.push_back(-1);
        // find the low bound of the range, O(lgn)
        int start = 0, end = n - 1;
        while (start < end)
        {
            int mid = (start + end) / 2;
            if (A[mid] < target)
            {
                start = mid + 1;
                continue;
            }
            end = mid;
        }
        int low_bound = A[start] == target ? start : -1;
        if (low_bound == -1)
        {
            return result;
        }
        // find the high bound of the range, O(lgn)
        start = low_bound, end = n;
        while (start < end)
        {
            int mid = (start + end) / 2;
            if (A[mid] > target)
            {
                end = mid;
                continue;
            }
            start = mid + 1;
        }
        int high_bound = start - 1;
        result.clear();
        result.push_back(low_bound);
        result.push_back(high_bound);
        return result;
    }
};