class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cur = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
                continue;
            nums[cur] = nums[i];
            cur++;
        }
        return cur;
    }
};