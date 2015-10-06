class Solution {
public:
    // simple version
    // int nthUglyNumber(int n) {
    //     vector<int> uglys(1, 1);
    //     int p2 = 0, p3 = 0, p5 = 0;
    //     while (uglys.size() < n) {
    //         int ugly2 = uglys[p2] * 2, ugly3 = uglys[p3] * 3, ugly5 = uglys[p5] * 5;
    //         int min_v = min(ugly2, min(ugly3, ugly5));
    //         if (min_v == ugly2) ++p2;
    //         if (min_v == ugly3) ++p3;
    //         if (min_v == ugly5) ++p5;
    //         if(min_v != uglys.back()) {
    //             // skip duplicate
    //             uglys.push_back(min_v);
    //         }
    //     }
    //     return uglys[n-1];
    // }

    int nthUglyNumber(int n) {
        vector<int> factors{ 2, 3, 5};
        return nthUglyNumberGeneral(n, factors);
    }

    int nthUglyNumberGeneral(int n, vector<int>& factors) {
        vector<int> uglys(1,1);
        vector<int> indexes(factors.size(), 0);
        
        while(uglys.size() < n) {
            int min_v = INT_MAX;
            int min_index = 0;
            for(int k =0; k< factors.size(); k++) {
                int temp = uglys[indexes[k]] * factors[k];
                if(temp < min_v) {
                    min_v = temp;
                    min_index = k;
                }
            }
            
            indexes[min_index]++;
            // need to avoid duplicate ugly number
            if(uglys[uglys.size()-1] != min_v) {
                uglys.push_back(min_v);
             }
        }
        
        return uglys[n-1];
    }
};
