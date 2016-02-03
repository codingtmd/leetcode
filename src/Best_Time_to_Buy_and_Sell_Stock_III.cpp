class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() <= 1) return 0;
    vector<int> maxFromLeft(prices.size(), 0);
    vector<int> maxFromRight(prices.size(), 0);
    int minV = INT_MAX, maxP = INT_MIN;
    for (int i = 0; i < prices.size(); i++)
    {
      if (minV > prices[i]) minV = prices[i];
      int temp = prices[i] - minV;
      if (temp > maxP) maxP = temp;
      maxFromLeft[i] = maxP;
    }

    int maxV = INT_MIN;
    maxP = INT_MIN;
    for (int i = prices.size() - 1; i >= 0; i--)
    {
      if (maxV < prices[i]) maxV = prices[i];
      int temp = maxV - prices[i];
      if (temp > maxP) maxP = temp;
      maxFromRight[i] = maxP;
    }

    int maxProfit = INT_MIN;
    for (int i = 0; i < prices.size() - 1; i++)
    {
      int sum = maxFromLeft[i] + maxFromRight[i + 1];
      if (sum > maxProfit) maxProfit = sum;
    }
    if (maxProfit < maxFromRight[0])
      maxProfit = maxFromRight[0];
    return maxProfit;
  }
};