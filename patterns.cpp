#include <iostream>
using namespace std;

class Patterns
{
    int height, width;

public:
    Patterns(int height = 5, int width = 5)
    {
        this->height = height;
        this->width = width;
        cout << this->height << endl
             << this->width << endl;
    }

    void printRectangle()
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                cout << "* ";
            }
            cout << endl;
        }
    }

    ~Patterns()
    {
        cout << "Destructor called." << endl;
    }
};

int main()
{
    Patterns p(2);
    p.printRectangle();

    return 0;
}