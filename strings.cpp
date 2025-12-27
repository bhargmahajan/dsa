#include <string>

using namespace std;

/*
    @description: class to solve string related problems
*/
class StringProblems
{
public:
    /*
        @description: removes the outermost parentheses from every primitive string in the input
        @param: s - input string containing valid parentheses
        @return: string with outermost parentheses removed
        @time complexity: O(n), where n is the length of the input string
        @space complexity: O(1), for the output string
    */
    string removeOuterParentheses(string s)
    {
        int cnt = 0;
        string res = "";
        for (char ch : s)
        {
            if (ch == '(')
            {
                if (cnt > 0)
                    res += ch;
                cnt++;
            }
            else if (ch == ')')
            {
                cnt--;
                if (cnt > 0)
                {
                    res += ch;
                }
            }
        }
        return res;
    }

    /*
        @description: reverses the order of words in a given string
        @param: s - input string containing words separated by spaces
        @return: string with words in reversed order
        @time complexity: O(n), where n is the length of the input string
        @space complexity: O(1), for the output string
    */
    string reverseWords(string s)
    {
        string res = "";
        int i = s.length() - 1;
        while (i >= 0)
        {
            while (i >= 0 && s[i] == ' ')
                i--;
            if (i < 0)
                break;
            int j = i;
            while (i >= 0 && s[i] != ' ')
            {
                i--;
            }
            res += s.substr(i + 1, j - i) + ' ';
        }

        return res.substr(0, res.length() - 1);
    }

    /*
        @description: finds the largest odd number that can be formed from the given string of digits
        @param: num - input string containing digits
        @return: string representing the largest odd number
        @time complexity: O(n), where n is the length of the input string
        @space complexity: O(1), for the output string
    */
    string largestOddNumber(string num)
    {
        int i = num.length() - 1;

        while (i >= 0)
        {
            if ((num[i] - '0') % 2 != 0)
                break;
            i--;
        }
        return num.substr(0, i + 1);
    }
};

int main()
{
    StringProblems str;
    string input = "(()())(())";
    string output = str.removeOuterParentheses(input);
    // Expected output: "()()()"
    return 0;
}