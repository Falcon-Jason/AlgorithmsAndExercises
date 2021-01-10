#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
set<int> theGraph[100010];
int graphSize;

void readGraph() {
    cin >> graphSize;
    for (int i = 0; i < graphSize; i++) {
        int m, n;
        cin >> m >> n;
        theGraph[m].insert(n);
        theGraph[n].insert(m);
    }
}

void printGraph() {
    for (int i = 0; i < graphSize; i++) {
        cout << i << ":";
        for (set<int>::iterator j = theGraph[i].begin(); j != theGraph[i].end(); j++) {
            cout << " " << *j;
        }
        cout << endl;
    }
}

int path[100010];
int pathSize = 0;
int pathPlace(int vertex) {
    for (int i = 0; i < pathSize; i++) {
        if (path[i] == vertex) {
            return i;
        }
    }
    return -1;
}

int search(int current, int previous) {
    int place = pathPlace(current);
    if (place > 0) {
        return place;
    }

    path[pathSize++] = current;

    for (set<int>::iterator i = theGraph[current].begin(); i != theGraph[current].end(); ++i) {
        if (*i != previous) {
            if ((place = search(*i, current)) > 0) {
                return place;
            }
        }
    }

    pathSize--;
    return -1;
}

void printPath(int begin) {
    sort(path + begin, path + pathSize);

    cout << path[begin];
    for (int i = begin + 1; i != pathSize; i++) {
        cout << " " << path[i];
    }
    cout << endl;
}

int main() {
    readGraph();
    printPath(search(1, -1));
}