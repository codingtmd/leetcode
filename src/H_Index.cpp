class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::sort (citations.begin(), citations.end());   
        
        int length = citations.size();
        for(int i =0; i< length; i++) {
            int h = length - i;
            if(h<= citations[i]) {
                // return the first h
                return h;
            }
        }
        
        return 0;
    }
};