#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>

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
                    res += ch;
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
                i--;
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
        for (int i = 0; i < strs[0].size() && i < strs[strs.size() - 1].size(); i++)
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

    /*
        @description: sorts characters in a string by their frequency in descending order
        @param: s - input string
        @return: string with characters sorted by frequency
        @time complexity: O(n^2), where n is the length of the input string
        @space complexity: O(1), for the frequency array
    */
    string frequencySort(string s)
    {
        vector<int> freq(256, 0);

        for (char c : s)
            freq[c]++;

        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            int mx_freq = 0;
            char mx_char = 0;

            for (int j = 0; j < 256; j++)
            {
                if (freq[j] > mx_freq)
                {
                    mx_freq = freq[j];
                    mx_char = (char)j;
                }
            }

            if (mx_freq == 0)
                break;

            ans += string(mx_freq, mx_char);
            freq[mx_char] = 0;
        }
        return ans;
    }

    /*
        @description: finds the maximum depth of nested parentheses in a string
        @param: s - input string containing parentheses
        @return: integer representing the maximum depth of nested parentheses
        @time complexity: O(n), where n is the length of the input string
        @space complexity: O(1), for the depth counters
    */
    int maxDepth(string s)
    {
        int maxDep = 0, dep = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                dep++;
                maxDep = max(maxDep, dep);
            }
            else if (c == ')')
                dep--;
        }

        return maxDep;
    }

    /*
        @description: converts a Roman numeral string to an integer
        @param: s - input string containing Roman numerals
        @return: integer representation of the Roman numeral
        @time complexity: O(n), where n is the length of the input string
        @space complexity: O(1), for the Roman numeral mapping
    */
    int romanToInt(string s)
    {
        unordered_map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int res = 0;

        for (int i = 0; i < s.size() - 1; i++)
        {
            if (roman[s[i]] < roman[s[i + 1]])
                res -= roman[s[i]];
            else
                res += roman[s[i]];
        }

        return res + roman[s[s.size() - 1]];
    }

    /*
        @description: converts a string to a 32-bit signed integer (atoi)
        @param: s - input string
        @return: integer representation of the string
        @time complexity: O(n), where n is the length of the input string
        @space complexity: O(1), for the result variable
    */
    int myAtoi(string s)
    {
        int sign = 1, i = 0;
        long res = 0;

        while (i < s.size() && s[i] == ' ')
            i++;

        if (i == s.size())
            return 0;

        if (s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (s[i] == '+')
            i++;

        while (i < s.size() && isdigit(s[i]))
        {
            res = res * 10 + (s[i] - '0');
            if (sign * res >= INT_MAX)
                return INT_MAX;
            if (sign * res <= INT_MIN)
                return INT_MIN;
            i++;
        }
        return (int)sign * res;
    }

    int expandFromCenter(const string &str, int left, int right)
    {
        while (left >= 0 && right < str.length() && str[left] == str[right])
        {
            left--;
            right++;
        }
        return right - left - 1;
    }

    /*
        @description: finds the longest palindromic substring in a given string
        @param: str - input string
        @return: string representing the longest palindromic substring
        @time complexity: O(n^2), where n is the length of the input string
        @space complexity: O(1), for the output substring
    */
    string longestPalindrome(string str)
    {
        int start = 0, end = 0;

        for (int i = 0; i < str.length(); i++)
        {
            int lenOdd = expandFromCenter(str, i, i);
            int lenEven = expandFromCenter(str, i, i + 1);
            int maxLen = max(lenOdd, lenEven);

            if (maxLen > end - start)
            {
                start = i - (maxLen - 1) / 2;
                end = i + maxLen / 2;
            }
        }

        return str.substr(start, end - start + 1);
    }

    /*
        @description: calculates the total beauty of all substrings of a given string
        @param: s - input string
        @return: integer representing the total beauty of all substrings
        @time complexity: O(n^2 * m), where n is the length of the input string and m is the number of unique characters
        @space complexity: O(m), for the frequency map
    */
    int beautySum(string s)
    {
        int sum = 0, n = s.length();

        for (int i = 0; i < n; i++)
        {
            unordered_map<char, int> freq;
            for (int j = i; j < n; j++)
            {
                freq[s[j]]++;

                int maxi = INT_MIN;
                int mini = INT_MAX;
                for (auto it : freq)
                {
                    mini = min(mini, it.second);
                    maxi = max(maxi, it.second);
                }
                sum += (maxi - mini);
            }
        }
        return sum;
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