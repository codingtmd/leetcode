class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> factors{ 2, 3, 5};
        
        vector<int> uglys(1,1);
        vector<int> indexes(factors.size(), 0);
        
        for(int i =1; i< n; ) {
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
                i++;
            }
        }
        
        return uglys[n-1];
    }
};
