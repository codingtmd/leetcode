class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int length = nums.size();
		            
		for(int i =0; i< length; i++) {
			if(nums[i] == i+1) {
				continue;
			}
									                
			int oldIndex = i;
			int newIndex = nums[i]-1;
			while(nums[oldIndex] != oldIndex +1 ) {
				if(nums[oldIndex] == nums[newIndex] ) {
					return nums[oldIndex];
				}
				int temp = nums[newIndex];
				nums[newIndex] = nums[oldIndex];
				nums[oldIndex] = temp;
				
				newIndex = nums[oldIndex] -1;
			}
		}
	}
};
