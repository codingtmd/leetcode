class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > coll;
        vector<int> solution;
        if (num.size() == 0) return coll;
        vector<int> visited(num.size(), 0);
        sort(num.begin(), num.end());
        GeneratePermute(num, 0, visited, solution, coll);
        return coll;
    }
    void GeneratePermute(vector<int> & num, int step, vector<int>& visited, vector<int>& solution, vector<vector<int> >& coll)
    {
        if (step == num.size())
        {
            coll.push_back(solution);
            return;
        }
        for (int i = 0; i < num.size(); i++)
        {
            if (visited[i] == 0)
            {

                visited[i] = 1;
                solution.push_back(num[i]);
                GeneratePermute(num, step + 1, visited, solution, coll);
                solution.pop_back();
                visited[i] = 0;
                while (i < num.size() - 1 && num[i] == num[i + 1])
                    i++;
            }
        }
    }
};