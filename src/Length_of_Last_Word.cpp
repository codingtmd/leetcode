class Solution {
public:
    int lengthOfLastWord(const char *s) {
        const char* pStart = s;
        const char* pEnd = s;
        const char* p = s;
        const char* pre = s;

        while (*p != '\0')
        {
            if (*pre == ' ' && *p != ' ') pStart = p;
            if (*pre != ' ' && *p == ' ') pEnd = p;

            pre = p;
            p++;
        }

        if (*pre != ' ' && *p == '\0') pEnd = p;
        return pEnd - pStart;
    }
};