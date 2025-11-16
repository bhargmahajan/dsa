#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Hashes
{
    unordered_map<int, int> hashArray;

public:
    Hashes(vector<int> arr);

    int getFrequency(int key);

    ~Hashes();
};

Hashes::Hashes(vector<int> arr)
{
    for (auto x : arr)
    {
        this->hashArray[x]++;
    }
    cout << "Constructor called" << endl;
}

int Hashes::getFrequency(int key)
{
    return this->hashArray[key];
}

Hashes::~Hashes()
{
    cout << "Destructor called" << endl;
}

int main()
{
    vector<int> inArray = {10, 20, 30, 40, 50, 20};
    Hashes obj(inArray);

    cout << "Frequency: " << obj.getFrequency(20) << endl;

    return 0;
}