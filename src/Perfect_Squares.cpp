class Solution {
public:
    int numSquares(int n) {
        vector<int> dp_nums(1,0);
        
        while(dp_nums.size() <= n) {
            int k = dp_nums.size();
            int least_num = INT_MAX;
            for(int i =1; i*i <=k; i++){
                least_num = min(least_num, dp_nums[k-i*i] +1);               
            }
            dp_nums.push_back(least_num);
        }
        return dp_nums[n];
    }
};