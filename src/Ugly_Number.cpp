class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0) return false;
        
        int arr [] = { 2, 3, 5};
	    vector<int> factors(arr, arr + sizeof(arr) / sizeof(arr[0]));
        return ugly(num,factors);
    }
    
    bool ugly(int num, vector<int>& factors) {
        if(num == 1) {
            return true;
        }
        
        for(int i =0; i< factors.size(); i++) {
            if(num % factors[i] != 0) {
                continue;
            }
            if(ugly(num/factors[i], factors)) {
                return true;
            } 
        }
        return false;
    }
};