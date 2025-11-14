#include <iostream>
#include <vector>

using namespace std;

class arrays
{
public:
    arrays();
    ~arrays();
};

arrays::arrays()
{
    cout << "Arrays class constructor called." << endl;
}

arrays::~arrays()
{
    cout << "Arrays class destructor called." << endl;
}

int main()
{
    arrays arr;
    return 0;
}