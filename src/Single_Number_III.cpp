class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int length = nums.size();
        
        // get the xor result of the array, b ^ c
        int xor_result = 0;
        for(int i =0; i< length; i++) {
            xor_result ^= nums[i];
        }
        
        // get the K of first bit, which equals 1
        int first_one_index = 0;
        for(first_one_index =0; first_one_index< 32; first_one_index++) {
            if((xor_result>>first_one_index) & 1 == 1) {
                break;
            }
        }
        
        // use k to split the array into two part
        // xor the sub array, if the element's Kth bit also equals 1, b
        int xor_twice = 0;
        for(int i =0; i< length; i++) {
            if((nums[i]>>first_one_index) & 1 == 1) {
                xor_twice ^= nums[i];
            }
        }
        
        // with b, easy to get c by math
        vector<int> result = {xor_twice, xor_result ^ xor_twice };        
        return result;
    }
};