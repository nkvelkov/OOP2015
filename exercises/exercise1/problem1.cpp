#include <iostream>
#include <math.h>

using namespace std;

struct Point
{
    double x, y;

    void read()
    {
        cin >> x >> y; // x and y are visible in this method;
    }

    void print()
    {
        cout << "("<< x << " " << y << ")" << endl; //x and y are visible in this method;
    }
};

int main()
{
    Point p, q, r; // instantiation of three points;

    p.read(); // initializing the x and y coordinates of the three points
    q.read();
    r.read();

    p.print();
    q.print();
    r.print();

    return 0;
}
