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
};

int main()
{
    StringProblems str;
    string input = "(()())(())";
    string output = str.removeOuterParentheses(input);
    // Expected output: "()()()"
    return 0;
}