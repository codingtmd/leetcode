class Solution {
public:
    bool isValid(string s) {
        stack<char> container;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                container.push(s[i]);
                continue;
            }
            if (container.size() == 0) return false;

            char top = container.top();
            container.pop();
            if (s[i] == ')' && top != '(') return false;
            if (s[i] == '}' && top != '{') return false;
            if (s[i] == ']' && top != '[') return false;
        }

        if (container.size() > 0) return false;
        return true;
    }
};