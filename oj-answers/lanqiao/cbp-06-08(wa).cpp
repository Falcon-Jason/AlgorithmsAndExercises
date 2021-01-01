#include <iostream>

using namespace std;
struct point
{
    int x;
    int y;
};

int distance(point p1, point p2)
{
    return (abs(p1.y - p2.y) + abs(p1.x - p2.x));
}

int main()
{
    int width;
    int id1, id2;
    point p1, p2;

    cin >> width >> id1 >> id2;

    p1.y = (id1 - 1) / width;
    p2.y = (id2 - 1) / width;

    p1.x = p1.y % 2 ? width - (id1 - 1) % width - 1 : (id1 - 1) % width;
    p2.x = p2.y % 2 ? width - (id2 - 1) % width - 1 : (id2 - 1) % width;

    cout << distance(p1, p2);
    
    return 0;
}