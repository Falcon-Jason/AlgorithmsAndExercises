#include <iostream>
#include <string>
#define MAX_SIZE 0XFF
using namespace std;

void postOrder(const string pre, const string mid, string &post)
{
    if (pre == "" || mid == "")
    {
        return;
    }

    int i = mid.find(pre[0]);
    char to_append[2] = {pre[0], '\0'};
    postOrder(pre.substr(1, i), mid.substr(0, i), post);
    postOrder(pre.substr(i + 1, pre.size() - i), mid.substr(i + 1, mid.size() - i), post);
    
    post.append(to_append);
}

int main()
{
    string pre;
    string mid;
    string post;

    while (cin >> pre >> mid)
    {
        postOrder(pre, mid, post);
        cout << post << endl;
        post.clear();
    }
    return 0;
}

// Accepted: https://vjudge.net/solution/18366931