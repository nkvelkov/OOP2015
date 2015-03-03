#include <iostream>

using namespace std;

struct Point
{
    double x, y;

    void read()
    {
        cin >> x >> y;
    }

    void print()
    {
        cout << "(" << x << ", " << y << ")\n";
    }
};

int main()
{
    Point p, q, r; // instantiation of three points;

    p.read(); // initializing the x and y coordinates of the three points
    q.read();
    r.read();

    double a, b, c;
    a = sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
    b = sqrt((r.x - q.x) * (r.x - q.x) + (r.y - q.y) * (r.y - q.y));
    c = sqrt((p.x - r.x) * (p.x - r.x) + (p.y - r.y) * (p.y - r.y));

    cout << boolalpha << ((a + b > c) && (b + c > a) && (a + c > b)) << endl;

    return 0;
}
