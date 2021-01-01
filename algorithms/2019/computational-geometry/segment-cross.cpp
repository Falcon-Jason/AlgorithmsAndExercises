#include <iostream>

using namespace std;

inline int isDiffSign(int a, int b)
{
    return (a > 0 && b < 0) || (a < 0 && b > 0);
}

struct Point
{
    int x;
    int y;

    Point(int x = 0, int y = 0)
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

    static int crossProduct(Point &p0, Point &p1, Point &p2)
    {
        int x1, y1, x2, y2;
        x1 = p1.x - p0.x;
        x2 = p2.x - p0.x;
        y1 = p1.y - p0.y;
        y2 = p2.y - p0.y;
        return x1 * y2 - x2 * y1;
    }

    static int crossProduct(Point p1, Point p2)
    {
        return p1.x * p2.y - p2.x * p1.y;
    }
};

struct Segment
{
    Point begin;
    Point end;

    Segment(Point &begin, Point &end)
    {
        this->begin = begin;
        this->end = end;
    }

    static bool isLineCross(Segment l1, Segment l2)
    {
        int pd1 = Point::crossProduct(l1.begin, l1.end, l2.begin);
        int pd2 = Point::crossProduct(l1.begin, l1.end, l2.end);
        return isDiffSign(pd1, pd2);
    }

    static bool isOnline(Point &p, Segment &l)
    {
        return Point::crossProduct(l.begin, l.end, p) == 0;
        return false;
    }

    static bool isSegmentCross(Segment s1, Segment s2)
    {
        if (isLineCross(s1, s2) && isLineCross(s2, s1))
        {
            return true;
        }
        else if (isOnline(s1.begin, s2) || isOnline(s1.end, s2) ||
                 isOnline(s2.begin, s1) || isOnline(s2.end, s1))
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Point p1, p2;
    Point p3, p4;
    cin >> p1 >> p2;
    cin >> p3 >> p4;
    Segment s1{p1, p2};
    Segment s2{p3, p4};

    // cout << boolalpha << Segment::isLineCross(s1, s2) << ' ' << Segment::isLineCross(s2, s1) << endl;
    cout << boolalpha << Segment::isSegmentCross(s1, s2) << endl;
    return 0;
}