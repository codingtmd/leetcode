class Solution {
public:
    int hIndex(vector<int>& citations) {
        int start = 0, end = citations.size()-1;
        
        int max_h = 0;
        while(start<=end) {
            int mid = start + (end - start)/2;
            int h = citations.size() - mid;
            if(h<= citations[mid]) {
                end = mid -1;
                max_h = h;
            } else {
                start = mid +1;
            }
        }
        
        return max_h;
    }
};