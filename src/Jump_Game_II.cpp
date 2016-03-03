class Solution {
public:
  int jump(vector<int>& nums) {
    int start = 0;   
    int end = 0;   
    int count =0;   
    int n = nums.size();
    if(n == 1) return 0;   
    while(end < n)   
    {   
      int max = 0;   
      count++;   
      for(int i =start; i<= end ; i++ )   
      {    
        if(nums[i]+i >= n-1)   
        {        
          return count;   
        }   
        if(nums[i]+ i > max)   
          max = nums[i]+i;   
      }   
      start = end+1;   
      end = max;      
    }   
  }   
};