/*
    @author: Bharg Mahajan
    @description: This file contains various bit manipulation problems solutions implemented in C++.
*/
#include <bits/stdc++.h>
using namespace std;

/*
    @author: Bharg Mahajan
    @description: This class contains various bit manipulation problems solutions implemented in C++.
*/
class bitManipulation
{
public:
    bitManipulation();

    /*
        @description: This function checks if a number is a power of two.
        @param: n - the number to check.
        @return: true if n is a power of two, false otherwise.
        Time Complexity: O(1)
        Space Complexity: O(1)
    */
    bool isPowerOfTwo(int n) { return n > 0 && (n & (n - 1)) == 0; }

    /*
        @description: This function divides two integers without using multiplication, division and mod operator.
        @param: dividend - the number to be divided.
                divisor - the number to divide by.
        @return: the quotient after dividing dividend by divisor.
        Time Complexity: O(log (n)^2)
        Space Complexity: O(1)
    */
    int divide(int dividend, int divisor)
    {
        if (dividend == divisor)
            return 1;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (1 == divisor)
            return dividend;

        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        int ans = 0;
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        while (n >= d)
        {
            int p = 0;

            while (n >= (d << p))
                p++;

            p--;
            n -= d << p;
            ans += 1 << p;
        }

        return sign * ans;
    }

    ~bitManipulation();
};

int main()
{
    bitManipulation sol;
    return 0;
}