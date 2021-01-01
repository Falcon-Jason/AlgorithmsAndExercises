#include <cmath>
#include <iostream>

using namespace std;
int main()
{
    int counter = 0;
    double a, b, c;
    cin >> c;
    for (a = 1; a <= c; a++)
    {
        if(c * c - a * a < a * a)
        {
            break;
        }
        b = sqrt(c * c - a * a);
        if (b == (int)b)
            counter++;
    }
    cout << counter << endl;
    return 0;
}
