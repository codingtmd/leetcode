class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        bool star = false;
        const char *str, *ptr;
        for (str = s, ptr = p; *str != '\0'; str++, ptr++)
        {
            switch (*ptr)
            {
                case '?':
                    break;
                case '*':
                    star = true;
                    s = str, p = ptr;
                    while (*p == '*')
                        p++;
                    if (*p == '\0') // if nil after '*', return true
                        return true;
                    str = s - 1;
                    ptr = p - 1;
                    break;
                default:
                {
                    if (*str != *ptr)
                    {
                        // if no '*' in front, match failed
                        if (!star)
                            return false;
                        s++;
                        str = s - 1;
                        ptr = p - 1;
                    }
                }
            }
        }
        while (*ptr == '*')
            ptr++;
        return (*ptr == '\0');
    }
};