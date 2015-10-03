class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int zero_index = 0, none_zero_index = 0;
            none_zero_index < nums.size() && zero_index < nums.size(); 
        ) {
            if(nums[zero_index] != 0) {
                zero_index++;
                none_zero_index = zero_index;
                continue;
            } 
            
            if(nums[none_zero_index] == 0) {
                none_zero_index++;
                continue;
            }
            
            int temp = nums[zero_index];
            nums[zero_index] = nums[none_zero_index];
            nums[none_zero_index] = temp;
            zero_index++;
            none_zero_index++;
        }
    }
};