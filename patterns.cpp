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
        string output = "";

        for (int j = 0; j < width; j++)
        {
            output += "* ";
        }

        for (int i = 0; i < height; i++)
        {
            cout << output << endl;
        }
    }

    void printRightTriangle()
    {
        for (int i = 0; i < height; i++)
        {
            int flag;
            if (i % 2 == 0)
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }

            for (int j = 0; j <= i; j++)
            {
                cout << flag << " ";
                if (flag == 1)
                {
                    flag = 0;
                }
                else
                {
                    flag = 1;
                }
            }
            cout << endl;
        }
    }

    void printInvertedRightTriangle()
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j <= height - i - 1; j++)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void printTriangle()
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < height - i - 1; j++)
            {
                cout << " ";
            }

            for (int j = 0; j < 2 * i + 1; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }

    void printInvertedTriangle()
    {
        for (int i = height - 1; i >= 0; i--)
        {
            for (int j = 0; j < height - i - 1; j++)
            {
                cout << " ";
            }

            for (int j = 0; j < 2 * i + 1; j++)
            {
                cout << "*";
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
    Patterns p(5);

    cout << "Square Pattern:" << endl;
    p.printRectangle();

    cout << "Right Triangle Pattern:" << endl;
    p.printRightTriangle();

    cout << "Inverted Right Triangle Pattern:" << endl;
    p.printInvertedRightTriangle();

    cout << "Triangle Pattern:" << endl;
    p.printTriangle();

    cout << "Inverted Triangle Pattern:" << endl;
    p.printInvertedTriangle();

    return 0;
}