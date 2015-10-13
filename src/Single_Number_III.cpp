class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int length = nums.size();
        
        int xor_result = 0;
        for(int i =0; i< length; i++) {
            xor_result ^= nums[i];
        }
        
        int first_one_index = 0;
        for(first_one_index =0; first_one_index< 32; first_one_index++) {
            if((xor_result>>first_one_index) & 1 == 1) {
                break;
            }
        }
        
        int xor_twice = 0;

        for(int i =0; i< length; i++) {
            if((nums[i]>>first_one_index) & 1 == 1) {
                xor_twice ^= nums[i];
            }
        }
        
        vector<int> result = {xor_twice, xor_result ^ xor_twice };
        
        return result;
    }
};