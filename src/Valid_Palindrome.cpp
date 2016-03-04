class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        std::transform(
            s.begin(), s.end(), s.begin(), ::tolower);
        while (start < end)
        {
            //filter non-alpha char
            while (start < end && !isAlpha(s[start])) start++;
            //filter non-alpha char
            while (start < end && !isAlpha(s[end])) end--;
            if (s[start] != s[end]) break;
            start++;
            end--;
        }
        if (start >= end)
            return true;
        else
            return false;
    }
    bool isAlpha(char c)
    {
        if (c >= 'a' && c <= 'z') return true;
        if (c >= '0' && c <= '9') return true;
        return false;
    }
};