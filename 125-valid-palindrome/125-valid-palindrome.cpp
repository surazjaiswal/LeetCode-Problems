class Solution
{
    public:
        bool isPalindrome(string s)
        {
            string str = "";

            for (char c: s)
            {
                if (isalpha(c))
                {
                    str += tolower(c);
                }
                else if (isdigit(c))
                {
                    str += c;
                }
            }

            string rev = str;
            reverse(rev.begin(), rev.end());

            // cout << str << '\n' << rev << endl;

            return rev == str;
        }
};