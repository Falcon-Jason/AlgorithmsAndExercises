#include <iostream>

using namespace std;

struct Point
{
    double x;
    double y;

    Point(double x = 0, double y = 0)
    {
        this->x = x;
        this->y = y;
    }

    friend istream &operator>>(istream &in, Point &p)
    {
        return in >> p.x >> p.y;
    }

    friend ostream &operator<<(ostream &out, Point &p)
    {
        return out << p.x << p.y;
    }

    static double crossProduct(Point &p1, Point &p2, Point &p0)
    {
        double x1, y1, x2, y2;
        x1 = p1.x - p0.x;
        x2 = p2.x - p0.x;
        y1 = p1.y - p0.y;
        y2 = p2.y - p0.y;
        return x1 * y2 - x2 * y1;
    }

    static double crossProduct(Point &p1, Point &p2)
    {
        return p1.x * p2.y - p2.x * p1.y;
    }
};

int main()
{
    Point p1, p2;
    cin >> p1 >> p2;
    cout << Point::crossProduct(p1, p2) << endl;
}