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

    void printRightTriangle()
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << j << " ";
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
    Patterns p(4);

    cout << "Square Pattern:" << endl;
    p.printRectangle();

    cout << "Right Triangle Pattern:" << endl;
    p.printRightTriangle();

    return 0;
}