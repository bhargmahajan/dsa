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

    void printHollowRectangle()
    {
        string line = "* ", hollow = "* ";

        for (int j = 1; j < width - 1; j++)
        {
            hollow += "  ";
            line += "* ";
        }
        hollow += "*";
        line += "*";

        for (int i = 0; i < height; i++)
        {
            if (i == 0 || i == height - 1)
                cout << line << endl;
            else
                cout << hollow << endl;
        }
    }

    void printNumberRectangle()
    {
        for (int i = 0; i < 2 * height - 1; i++)
        {
            for (int j = 0; j < 2 * height - 1; j++)
            {
                int top = i;
                int left = j;
                int right = (2 * height - 2) - j;
                int bottom = (2 * height - 2) - i;

                cout << height - min(min(top, bottom), min(left, right)) << " ";
            }
            cout << endl;
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
            for (char ch = 'A'; ch <= 'A' + (height - i - 1); ch++)
            {
                cout << ch << " ";
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

    void printHorns()
    {
        for (int i = 1; i <= height; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << j;
            }

            for (int j = 1; j <= 2 * (height - i); j++)
            {
                cout << " ";
            }

            for (int j = i; j >= 1; j--)
            {
                cout << j;
            }
            cout << endl;
        }
    }

    void printInvertedHorns()
    {
        for (int i = height; i > 0; i--)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << "*";
            }

            for (int j = 1; j <= 2 * (height - i); j++)
            {
                cout << " ";
            }

            for (int j = 1; j <= i; j++)
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
    Patterns p(4);

    cout << "Square Pattern:" << endl;
    p.printRectangle();

    cout << "Hollow Square Pattern:" << endl;
    p.printHollowRectangle();

    cout << "Number Rectangle Pattern:" << endl;
    p.printNumberRectangle();

    cout << "Right Triangle Pattern:" << endl;
    p.printRightTriangle();

    cout << "Inverted Right Triangle Pattern:" << endl;
    p.printInvertedRightTriangle();

    cout << "Triangle Pattern:" << endl;
    p.printTriangle();

    cout << "Inverted Triangle Pattern:" << endl;
    p.printInvertedTriangle();

    cout << "Horns Pattern:" << endl;
    p.printHorns();

    cout << "Inverted Horns Pattern:" << endl;
    p.printInvertedHorns();

    return 0;
}