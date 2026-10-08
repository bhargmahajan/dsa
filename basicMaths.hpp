#define BASICMATHS_H
#include <bits/stdc++.h>

using namespace std;

/*
 * @author: Bharg Mahajan
 * @description: This class contains basic maths functions.
 */
class BasicMaths
{
public:
    /*
     * @brief Counts the number of digits in an integer.
     * @param n The integer to count digits for.
     * @return The number of digits in n.
     * @time_complexity: O(log10(n)), where n is the input integer.
     * @space_complexity: O(1)
     */
    int countDigit(int n)
    {
        if (n == 0)
            return 1;

        int res = 0;

        while (n > 0)
        {
            n /= 10;
            res++;
        }

        return res;
    }

    /*
     * @brief Counts the number of odd digits in an integer.
     * @param n The integer to count odd digits for.
     * @return The number of odd digits in n.
     * @time_complexity: O(log10(n)), where n is the input integer.
     * @space_complexity: O(1)
     */
    int countOddDigit(int n)
    {
        int res = 0;
        while (n > 0)
        {
            if ((n % 10) % 2 != 0)
                res++;
            n /= 10;
        }

        return res;
    }

    /*
     * @brief Reverses the digits of an integer.
     * @param n The integer to reverse.
     * @return The reversed integer.
     * @time_complexity: O(d), where d is the number of digits in n.
     * @space_complexity: O(d), for storing the string representation of n.
     */
    int reverseNumber(int n)
    {
        string str = to_string(n);
        reverse(str.begin(), str.end());
        int rev = stoi(str);

        return rev;
    }

    /*
     * @brief Checks if an integer is a palindrome.
     * @param n The integer to check.
     * @return True if n is a palindrome, false otherwise.
     * @time_complexity: O(d), where d is the number of digits in n.
     * @space_complexity: O(d), for storing the string representation of n.
     */
    bool isPalindrome(int n)
    {
        return reverseNumber(n) == n;
    }

    /*
     * @brief Finds the largest digit in an integer.
     * @param n The integer to find the largest digit for.
     * @return The largest digit in n.
     * @time_complexity: O(log10(n)), where n is the input integer.
     * @space_complexity: O(1)
     */
    int largestDigit(int n)
    {
        if (n == 0)
            return 0;

        int res = INT_MIN;
        while (n > 0)
        {
            if ((n % 10) > res)
                res = n % 10;
            n /= 10;
        }

        return res;
    }

    /*
     * @brief Calculates the factorial of an integer.
     * @param n The integer to calculate the factorial for.
     * @return The factorial of n.
     * @time_complexity: O(n), where n is the input integer.
     * @space_complexity: O(1)
     */
    int factorial(int n)
    {
        int res = 1;
        for (int i = 2; i <= n; i++)
            res *= i;

        return res;
    }

    /*
     * @brief Raises an integer to a power.
     * @param n The base integer.
     * @param exp The exponent.
     * @return n raised to the power of exp.
     * @time_complexity: O(log(exp)), where exp is the exponent.
     * @space_complexity: O(1)
     */
    int raisePower(int n, int exp)
    {
        int res = 1;

        while (exp > 0)
        {
            if (exp % 2 == 1)
                res *= n;

            n *= n;
            exp /= 2;
        }

        return res;
    }

    /*
     * @brief Checks if an integer is an Armstrong number.
     * @param n The integer to check.
     * @return True if n is an Armstrong number, false otherwise.
     * @time_complexity: O(d), where d is the number of digits in n.
     * @space_complexity: O(1)
     */
    bool isArmstrong(int n)
    {
        int original = n;

        if (n == 0)
            return true;

        int dig = countDigit(n);
        int res = 0;

        while (n > 0)
        {
            res += raisePower(n % 10, dig);
            n /= 10;
        }

        return res == original;
    }

    /*
     * @brief Checks if an integer is a perfect number.
     * @param num The integer to check.
     * @return True if num is a perfect number, false otherwise.
     * @time_complexity: O(sqrt(num)), where num is the input integer.
     * @space_complexity: O(1)
     */
    bool checkPerfectNumber(int num)
    {
        if (num <= 1)
            return false;

        int sum = 1;

        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                if (i * i == num)
                    sum += i;
                else
                    sum += i + (num / i);
            }
        }

        return num == sum;
    }

    /*
     * @brief Checks if an integer is a prime number.
     * @param n The integer to check.
     * @return True if n is a prime number, false otherwise.
     * @time_complexity: O(sqrt(n)), where n is the input integer.
     * @space_complexity: O(1)
     */
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;

        if (n == 2)
            return true;

        if (n % 2 == 0)
            return false;

        for (int i = 3; i * i <= n; i += 2)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    /*
     * @brief Counts the number of prime numbers less than a given integer.
     * @param n The integer to count primes for.
     * @return The number of prime numbers less than n.
     * @time_complexity: O(n * sqrt(n)), where n is the input integer.
     * @space_complexity: O(1)
     */
    int countPrimes(int n)
    {
        int res = 0;

        for (int i = 2; i < n; i++)
        {
            if (isPrime(i))
                res++;
        }

        return res;
    }

    /*
     * @brief Calculates the greatest common divisor (GCD) of two integers.
     * @param n1 The first integer.
     * @param n2 The second integer.
     * @return The GCD of n1 and n2.
     * @time_complexity: O(log(min(n1, n2))), where n1 and n2 are the input integers.
     * @space_complexity: O(1)
     */
    int GCD(int n1, int n2)
    {
        while (n2 != 0)
        {
            int temp = n2;
            n2 = n1 % n2;
            n1 = temp;
        }

        return n1;
    }

    /*
     * @brief Calculates the least common multiple (LCM) of two integers.
     * @param n1 The first integer.
     * @param n2 The second integer.
     * @return The LCM of n1 and n2.
     * @time_complexity: O(log(min(n1, n2))), where n1 and n2 are the input integers.
     * @space_complexity: O(1)
     */
    int LCM(int n1, int n2) { return n1 * n2 / GCD(n1, n2); }

    /*
     * @brief Finds all divisors of an integer.
     * @param n The integer to find divisors for.
     * @return A vector containing all divisors of n.
     * @time_complexity: O(sqrt(n)), where n is the input integer.
     * @space_complexity: O(d), where d is the number of divisors of n.
     */
    vector<int> divisors(int n)
    {
        vector<int> div, right;

        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                div.push_back(i);

                if (i != n / i)
                    right.push_back(n / i);
            }
        }

        for (int i = right.size() - 1; i >= 0; i--)
            div.push_back(right[i]);

        return div;
    }
};