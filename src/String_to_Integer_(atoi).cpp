class Solution {
public:
    int myAtoi(string str) {
        int num = 0;
        int sign = 1;
        int len = str.size();
        int i = 0;
        int signNum = 0;
        while (str[i] == ' ' && i < len) i++;
        if (str[i] == '+') {
            i++;
            signNum++;
        }
        if (str[i] == '-')
        {
            if (signNum > 0) return 0; // "+-2" => 0
            sign = -1;
            i++;
        }
        for (; i < len; i++)
        {
            if (str[i] == ' ') break;
            if (str[i] < '0' || str[i] > '9') break;
            if (INT_MAX / 10 < num
                    || INT_MAX / 10 == num
                    && INT_MAX % 10 < (str[i] - '0'))
            {
                return sign == -1 ? INT_MIN : INT_MAX;
                break;
            }
            num = num * 10 + str[i] - '0';
        }
        return num * sign;
    }
};