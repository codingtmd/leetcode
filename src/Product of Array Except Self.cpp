class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> products;
        if(nums.size() == 0) return products;

        int product = 1;
        products.push_back(1);
        for(int i =1; i< nums.size(); i++) {
            product *= nums[i-1];
            products.push_back(product);
        }
        
        product = 1;
        for(int i =nums.size()-2; i>=0; i--) {
            product = product * nums[i+1];
            products[i] = products[i] * product; 
        }
        return products;
    }
};