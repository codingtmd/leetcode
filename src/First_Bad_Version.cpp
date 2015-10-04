// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 0, end = n-1;
        while(start <=end) {
            int mid = start + (end - start)/2;
            bool isBad = isBadVersion(mid);
            if(isBad == false) {
                start = mid +1;
            } else {
                end = mid-1;
            }
        }
        
        return start;
    }
};