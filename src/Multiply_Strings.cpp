class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1.size() == 0 || num2.size() == 0) return 0;
    string res(num1.size() + num2.size() + 1, '0');
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());
    for (int i = 0; i < num1.size(); i++)
    {
      int dig1 = num1[i] - '0';
      int carry = 0;
      for (int j = 0; j < num2.size(); j++)
      {
        int dig2 = num2[j] - '0';
        int exist = res[i + j] - '0';
        res[i + j] = (dig1 * dig2 + carry + exist) % 10 + '0';
        carry = (dig1 * dig2 + carry + exist) / 10;
      }
      if (carry > 0)
      {
        res[i + num2.size()] = carry + '0';
      }
    }
    std::reverse(res.begin(), res.end());
    int start = 0;
    while (res[start] == '0' && start < res.size())
    {
      start++;
    }
    if (start == res.size()) return "0";
    return res.substr(start, res.size() - start);
  }
};