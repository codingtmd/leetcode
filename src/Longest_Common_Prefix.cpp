class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    string prefix;
    if (strs.size() == 0) return prefix;
    int len = 0;
    while (1)
    {
      char var;
      int i = 0;
      for (; i < strs.size(); i++)
      {
        if (i == 0) var = strs[0][len];
        if (strs[i].size() == len || var != strs[i][len])
          break;
      }
      if (i != strs.size())
        break;
      len++;
      prefix.append(1, var);
    }
    return prefix;
  }
};