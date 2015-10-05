class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int length = nums.size();
        for(int i =0; i< length; i++) {
            if(nums[i] == i) {
                continue;
            }
            
            int j=i;
            while(nums[j]<length && j != nums[j]) {
                int temp = nums[j];
                nums[j] = nums[temp];
                nums[temp] = temp;
            }
        }
        
        for(int i =0; i< length; i++) {
            if(nums[i] != i)
                return i;
        }
        return length;
    }
};