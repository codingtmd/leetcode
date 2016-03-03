class Solution {
public:
    void nextPermutation(vector<int> &num) {
        assert(num.size() > 0);
        int vioIndex = num.size() - 1;
        while (vioIndex > 0)
        {
            if (num[vioIndex - 1] < num[vioIndex])
                break;
            vioIndex --;
        }
        if (vioIndex > 0)
        {
            vioIndex--;
            int rightIndex = num.size() - 1;
            while (rightIndex >= 0 && num[rightIndex] <= num[vioIndex])
            {
                rightIndex --;
            }
            int swap = num[vioIndex];
            num[vioIndex] = num[rightIndex];
            num[rightIndex] = swap;
            vioIndex++;
        }
        int end = num.size() - 1;
        while (end > vioIndex)
        {
            int swap = num[vioIndex];
            num[vioIndex] = num[end];
            num[end] = swap;
            end--;
            vioIndex++;
        }
    }
};