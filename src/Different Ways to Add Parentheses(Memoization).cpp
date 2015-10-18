class Solution {
public:
    unordered_map<string, vector<int>> memo;
    int compute(int a, int b, char op) {
        switch(op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
        }
    }
    
    string generateKey(int startIndex, int endIndex) {
        return to_string(startIndex) + "-" + to_string(endIndex);
    }

    vector<int> diffWaysToCompute(string input) {
        return diffWaysToComputeWithMemo(input, 0, input.size()-1);
    }
    vector<int> diffWaysToComputeWithMemo(string& input, int startIndex, int endIndex) {    
        string cache_key = generateKey(startIndex, endIndex);
        if(memo.find(cache_key) != memo.end()) return memo[cache_key];
        
        int number = 0, i=startIndex;
        for(; i<= endIndex && isdigit(input[i]); ++i) {
            number  = number * 10 + input[i]-'0';
        }
        // if pure number, just return
        if(i > endIndex)  return {number};
        
        vector<int> diffWays, lefts, rights;
        for(int i =startIndex; i< endIndex; i++) {
            if(isdigit(input[i])) continue;
            lefts = 
                diffWaysToComputeWithMemo(input, startIndex, i-1);
            rights = 
                diffWaysToComputeWithMemo(input, i+1, endIndex );
            for(int j = 0; j < lefts.size(); ++j) 
                for( int k =0; k < rights.size(); ++k) 
                    diffWays.push_back(compute(lefts[j], rights[k], input[i]));
        }
        memo[cache_key] = diffWays;
        return diffWays;
    }
};