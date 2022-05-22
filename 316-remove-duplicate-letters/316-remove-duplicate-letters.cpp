class Solution {
public:
    string removeDuplicateLetters(string s) {
        // arr for marking last occurance of each char in given string
        vector<int> index(26, -1), visited(26, 0);
        for (int i = 0; i < s.length(); i++)
            index[s[i] - 'a'] = i;

        // stack for storing unique char and also for checking lexical ordering
        stack<char> stk;
        for (int i = 0; i < s.length(); i++)
        {
            // if char already present in stack
            if (visited[s[i] - 'a'])
                continue;
            // else char not visited
            // now we will check if stk contain any char at top that is lexically greater than current char and has occurance after curr char (later)
            while (stk.size() && stk.top() > s[i] && index[stk.top() - 'a'] > i)
            {
                // here stk.top has char which is lexically greater than curr char and has occurance later in char sequence
                // we will remove/pop that char from stk and and mark it as not visited
                visited[stk.top() - 'a'] = 0;
                stk.pop();
            }

            stk.push(s[i]);          // adding new char to stack
            visited[s[i] - 'a'] = 1; // marking it as visited
        }

        // at this stage stk contains only unique char present in given string which lexically smallest
        string ans = "";
        while (!stk.empty())
        {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end()); // reversing the string, stk follow LIFO
        return ans;
    }
};
