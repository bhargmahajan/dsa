#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

class maths
{
    int number;

public:
    maths(int number);
    int countDigits();
    int reverse();
    bool isPalindrome();
    bool isArmstrong();
    int gcd(int a, int b);
    ~maths();
};

maths::maths(int number)
{
    this->number = number;
    cout << "Constructor called" << endl;
}

int maths::countDigits()
{
    if (number < 0)
        number = -number;
    return log10(number) + 1;
}

int maths::reverse()
{
    int rev = 0, temp = number;

    while (temp != 0)
    {
        if (rev > INT_MAX / 10 || rev < INT_MIN / 10)
        {
            return 0;
        }
        rev = rev * 10 + (temp % 10);
        temp = temp / 10;
    }
    return rev;
}

bool maths::isPalindrome()
{
    if (number < 0)
        return 0;

    int rev = reverse();

    return rev == number;
}

bool maths::isArmstrong()
{
    if (number < 0)
        return 0;

    int digits = countDigits();
    int res = 0, temp = number;

    while (temp > 0)
    {
        if (res > INT_MAX / 10 || res < INT_MIN / 10)
        {
            return 0;
        }

        res += pow((temp % 10), digits);

        temp = temp / 10;
    }

    return res == number;
}

int maths::gcd(int a, int b)
{
    if (min(a, b) == 0)
        return max(a, b);

    gcd(max(a, b) % min(a, b), min(a, b));
}

maths::~maths()
{
    cout << "Destructor called" << endl;
}

int main()
{
    maths obj(153);

    cout << "Number of digits: " << obj.countDigits() << endl;

    cout << "Reversed number: " << obj.reverse() << endl;

    cout << "Is palindrome: " << (obj.isPalindrome() ? "Yes" : "No") << endl;

    cout << "Is Armstrong: " << (obj.isArmstrong() ? "Yes" : "No") << endl;

    cout << "GCD: " << obj.gcd(100, 35) << endl;

    return 0;
}