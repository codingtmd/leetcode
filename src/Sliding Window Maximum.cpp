class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        vector<int> maxWindow;
        for (int i = 0; i < nums.size(); ++i) {
            // deal with nums[i-k], nums[i]
            while(!maxWindow.empty() && nums[maxWindow.back()] < nums[i]) maxWindow.pop_back();
            if(!maxWindow.empty() && maxWindow.front() == i-k)  maxWindow.erase(maxWindow.begin());
            maxWindow.push_back(i);
            if (i >= k - 1) result.push_back(nums[maxWindow.front()]);
        }
        return result;
    }
};