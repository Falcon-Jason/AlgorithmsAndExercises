#include <cstring>
#include <iostream>

const int MAX_SIZE = 1100000;
int totalDays;
int totalOrders;

int roomsAvailable[MAX_SIZE];
int orderCount[MAX_SIZE];
int beginTime[MAX_SIZE];
int endTime[MAX_SIZE];

bool isValidOrder(int);
using namespace std;

int main()
{
    cin >> totalDays >> totalOrders;

    roomsAvailable[0] = 0;
    for (int i = 1; i <= totalDays; i++)
    {
        cin >> roomsAvailable[i];
    }

    orderCount[0] = 0;
    for (int i = 1; i <= totalOrders; i++)
    {
        cin >> orderCount[i] >> beginTime[i] >> endTime[i];
    }

    if (isValidOrder(totalOrders))
    {
        cout << 0 << endl;
        return 0;
    }

    int begin = 1;
    int end = totalOrders;
    while (begin < end)
    {
        int mid = (begin + end) / 2;
        if (isValidOrder(mid))
        {
            begin = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    cout << -1 << endl;
    cout << begin << endl;
    return 0;
}

int diffRoomRequird[MAX_SIZE];
int roomRequired[MAX_SIZE];

bool isValidOrder(int orderId)
{
    memset(diffRoomRequird, 0, sizeof(diffRoomRequird));

    for (int i = 1; i <= orderId; i++)
    {
        diffRoomRequird[beginTime[i]] += orderCount[i];
        diffRoomRequird[endTime[i] + 1] -= orderCount[i];
    }

    roomRequired[0] = 0;
    for (int i = 1; i <= totalOrders; i++)
    {
        roomRequired[i] = roomRequired[i - 1] + diffRoomRequird[i];
        if (roomRequired[i] > roomsAvailable[i])
        {
            return false;
        }
    }
    
    return true;
} // Unaccepted: https://www.luogu.org/recordnew/show/16688209 (#18 WA)