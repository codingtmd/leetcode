class Solution {
public:
    int searchInsert(vector<int>& A, int target) {
        int l = 0, r = A.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (A[mid] == target) return mid;
            if (mid > l && A[mid] > target && A[mid - 1] < target )
                return mid;
            if (A[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};