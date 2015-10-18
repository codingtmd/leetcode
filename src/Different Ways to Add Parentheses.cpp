class Solution {
public:
    int compute(int a, int b, char op) {
        switch(op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
        }
    }
    
    vector<int> diffWaysToCompute(string input) {
        int number = 0, i=0;
        for(; i< input.length() && isdigit(input[i]); ++i) {
            number  = number * 10 + input[i]-'0';
        }
        // if pure number, just return
        if(i == input.length())
            return {number};
        
        vector<int> diffWays, lefts, rights;
        for(int i =0; i< input.length(); i++) {
            if(isdigit(input[i])) continue;
            lefts = 
                diffWaysToCompute(input.substr(0, i));
            rights = 
                diffWaysToCompute(input.substr(i + 1, input.length() - i - 1));
            for(int j = 0; j < lefts.size(); ++j) {
                for( int k =0; k < rights.size(); ++k) {
                    diffWays.push_back(compute(lefts[j], rights[k], input[i]));
                }
            }
        }
        return diffWays;
    }
};