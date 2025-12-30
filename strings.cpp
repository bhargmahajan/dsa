#include <string>
#include <vector>
#include <algorithm>

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

    /*
        @description: finds the longest common prefix among an array of strings
        @param: strs - vector of input strings
        @return: string representing the longest common prefix
        @time complexity: O(n log n + m), where n is the number of strings and m is the length of the common prefix
        @space complexity: O(1), for the output string
    */
    string longestCommonPrefix(vector<string> &strs)
    {
        string res = "";
        sort(strs.begin(), strs.end());
        for (int i = 0;
             i < strs[0].size() && i < strs[strs.size() - 1].size();
             i++)
        {
            if (strs[0][i] == strs[strs.size() - 1][i])
                res += strs[0][i];
            else
                break;
        }
        return res;
    }

    /*
        @description: checks if two strings are isomorphic
        @param: s - first input string
        @param: t - second input string
        @return: boolean indicating if the strings are isomorphic
        @time complexity: O(n), where n is the length of the input strings
        @space complexity: O(1), for the character mapping arrays
    */
    bool isIsomorphic(string s, string t)
    {
        int sTemp[256] = {0}, tTemp[256] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            if (sTemp[s[i]] != tTemp[t[i]])
                return false;
            sTemp[s[i]] = i + 1;
            tTemp[t[i]] = i + 1;
        }

        return true;
    }

    /*
        @description: checks if one string can be obtained by rotating another string
        @param: s - first input string
        @param: goal - second input string
        @return: boolean indicating if s can be rotated to form goal
        @time complexity: O(n), where n is the length of the input strings
        @space complexity: O(n), for the temporary concatenated string
    */
    bool rotateString(string s, string goal)
    {
        if (s.length() != goal.length())
            return false;

        string temp = s + s;
        return temp.find(goal) != string::npos;
    }

    /*
        @description: checks if two strings are anagrams
        @param: s - first input string
        @param: t - second input string
        @return: boolean indicating if the strings are anagrams
        @time complexity: O(n), where n is the length of the input strings
        @space complexity: O(1), for the character frequency array
    */
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        int temp[26] = {0};

        for (int i = 0; i < s.length(); i++)
            temp[s[i] - 'a']++;

        for (int i = 0; i < t.length(); i++)
            temp[t[i] - 'a']--;

        for (int i = 0; i < 26; i++)
        {
            if (temp[i] != 0)
                return false;
        }

        return true;
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