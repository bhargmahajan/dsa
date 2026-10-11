#ifndef STRINGPROBLEMS_HPP
#define STRINGPROBLEMS_HPP

#include <bits/stdc++.h>

using namespace std;

/*
 * @author: Bharg Mahajan
 * @description: This class contains string functions.
 */
class StringProblems
{
    /*
     * @brief Reverses a string in place.
     * @param s The string to be reversed.
     * @time_complexity: O(n), where n is the length of the string.
     * @space_complexity: O(1)
     */
    void reverseString(vector<char> &s)
    {
        int i = 0, j = s.size() - 1;

        while (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    /*
     * @brief Checks if a string is a palindrome, considering only alphanumeric characters and ignoring cases.
     * @param s The string to be checked.
     * @return True if the string is a palindrome, false otherwise.
     * @time_complexity: O(n), where n is the length of the string.
     * @space_complexity: O(1)
     */
    bool isPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;

        while (i < j)
        {
            while (i < j && !isalnum(s[i]))
                i++;

            while (i < j && !isalnum(s[j]))
                j--;

            if (tolower(s[i]) != tolower(s[j]))
                return false;

            i++;
            j--;
        }

        return true;
    }

    /*
     * @brief Finds the longest common prefix string amongst an array of strings.
     * @param str The array of strings.
     * @return The longest common prefix string. If there is no common prefix, return an empty string "".
     * @time_complexity: O(n log n), where n is the number of strings in the array.
     * @space_complexity: O(1)
     */
    string longestCommonPrefix(vector<string> &str)
    {
        sort(str.begin(), str.end());

        string res = "";
        for (int i = 0; i < str[0].size() && i < str[str.size() - 1].size();
             i++)
        {
            if (str[0][i] == str[str.size() - 1][i])
                res += str[0][i];
            else
                break;
        }

        return res;
    }

    /*
     * @brief Checks if two strings are isomorphic.
     * @param s The first string.
     * @param t The second string.
     * @return True if the strings are isomorphic, false otherwise.
     * @time_complexity: O(n), where n is the length of the strings.
     * @space_complexity: O(1)
     */
    bool isomorphicString(string s, string t)
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
     * @brief Checks if one string can be rotated to become another string.
     * @param s The original string.
     * @param goal The target string after rotation.
     * @return True if the original string can be rotated to become the target string, false otherwise.
     * @time_complexity: O(n), where n is the length of the strings.
     * @space_complexity: O(n)
     */
    bool rotateString(string &s, string &goal)
    {
        if (s.size() != goal.size())
            return false;

        string temp = s + s;
        return temp.find(goal) != string::npos;
    }

    /*
     * @brief Checks if two strings are anagrams of each other.
     * @param s The first string.
     * @param t The second string.
     * @return True if the strings are anagrams, false otherwise.
     * @time_complexity: O(n), where n is the length of the strings.
     * @space_complexity: O(1)
     */
    bool anagramStrings(string &s, string &t)
    {
        unordered_map<char, int> hash;
        for (char c : s)
            hash[c]++;

        for (char c : t)
            hash[c]--;

        for (auto it : hash)
        {
            if (it.second != 0)
                return false;
        }

        return true;
    }

    /*
     * @brief Sorts the characters in a string based on their frequency in descending order.
     * @param s The string to be sorted.
     * @return The string with characters sorted by frequency.
     * @time_complexity: O(n^2), where n is the length of the string.
     * @space_complexity: O(1)
     */
    string frequencySort(string s)
    {
        vector<int> freq(256, 0);

        for (char c : s)
        {
            freq[c]++;
        }

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
};

#endif