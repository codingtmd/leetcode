class Solution {
public:
  vector<string> letterCombinations(string digits) {
    string trans[] = {"", " ", "abc", "def", "ghi", "jkl",
                      "mno", "pqrs", "tuv", "wxyz"
                     };
    vector<string> set;
    string seq;
    Generater(trans, digits, 0, seq, set);
    return set;
  }
  void Generater(string trans[], string& digits,
                 int deep, string& result, vector<string>& set)
  {
    if (deep == digits.size())
    {
      if (result != "")
        set.push_back(result);
      return;
    }

    // convert ACSII code to integer
    int curDig = digits[deep] - 48;
    for (int i = 0; i < trans[curDig].size(); i++)
    {
      result.push_back(trans[curDig][i]);
      Generater(trans, digits, deep + 1, result, set);
      result.resize(result.size() - 1);
    }
  }
};