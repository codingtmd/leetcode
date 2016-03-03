class Solution {
public:

    vector<string> restoreIpAddresses(string s) {
        vector<string> col;
        string ip;
        partitionIP(s, 0, 0, ip, col);
        return col;
    }
    void partitionIP(string s, int startIndex, int partNum,
                     string resultIp, vector<string>& col)
    {
        //max: 3 bits per partition
        if (s.size() - startIndex > (4 - partNum) * 3) return;
        //min: 1 bit per partition
        if (s.size() - startIndex < (4 - partNum)) return;
        if (startIndex == s.size() && partNum == 4)
        {
            resultIp.resize(resultIp.size() - 1);
            col.push_back(resultIp);
            return;
        }
        int num = 0;
        for (int i = startIndex; i < startIndex + 3; i++)
        {
            num = num * 10 + (s[i] - '0');
            if (num <= 255)
            {
                resultIp += s[i];
                partitionIP(s, i + 1, partNum + 1, resultIp + '.', col);
            }
            if (num == 0) //0.0.0.0 valid, but need to avoid 0.1.010.01
            {
                break;
            }
        }
    }

};