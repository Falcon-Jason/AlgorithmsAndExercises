#include <iostream>
#include <list>
#include <map>

using namespace std;

int main() {
    int ncard, nop;
    cin >> ncard >> nop;

    list<int> theList;
    map<int, list<int>::iterator> theMap;
    for (int i = 0; i < ncard; i++) {
        int cid;
        cin >> cid;
        theList.push_back(cid);
        theMap[cid] = --theList.end();
    }

    for (int i = 0; i < nop; i++) {
        int cid;
        cin >> cid;
        theList.erase(theMap[cid]);
        theList.push_front(cid);
        theMap[cid] = theList.begin();
    }

    for (auto i = theList.begin(); i != theList.end(); ++i) {
        cout << *i << " ";
    }
}
// Accepted: 33921438