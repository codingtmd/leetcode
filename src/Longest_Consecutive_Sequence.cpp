class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> hashmap;
        vector<int> length(num.size(), 0);
        for (int i = 0; i < num.size(); i++)
        {
            hashmap[num[i]] = i;
        }

        for (int i = 0; i < num.size(); i++)
        {
            // already calculate the length
            if (length[i] > 0) continue;

            length[i] = consecutiveLength(num[i], hashmap, length);
        }

        int maxV = INT_MIN;
        for (int i = 0; i < num.size(); i++)
        {
            maxV = length[i] > maxV ? length[i] : maxV;
        }
        return maxV;
    }

    int consecutiveLength(int num, unordered_map<int, int>& hashmap, vector<int>& length)
    {
        if (hashmap.find(num) == hashmap.end()) return 0;

        int index = hashmap[num];
        if (length[index] > 0)  return length[index];
        else
        {
            // hit each fresh node only once
            length[index] = consecutiveLength(num - 1, hashmap, length) + 1;
            return length[index];
        }
    }
};