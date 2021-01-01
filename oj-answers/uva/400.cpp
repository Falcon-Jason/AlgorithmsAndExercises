#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define WIDTH 60

using namespace std;

string files[128];
int nfile;

void list_files(int width);

int main() {
    while (cin >> nfile) {
        size_t max_length = 0;
        for (int i = 0; i < nfile; i++) {
            cin >> files[i];
            max_length = max((size_t)max_length, files[i].size());
        }
        sort(files, files + nfile);
        list_files(max_length);
    }
}

void print_dashes();
void print_file(int id, int width);

void list_files(int width) {
    int ncol = (WIDTH + 2) / (width + 2);
    int nline = nfile / ncol + !!(nfile % ncol);
    // cout << ncol << " " << nline << endl;
    print_dashes();
    for (int i = 0; i < nline; i++) {
        print_file(i, width);
        for (int j = i + nline; j < nfile; j += nline) {
            cout << "  ";
            print_file(j, width);
        }
        cout << endl;
    }
}

void print_dashes() {
    for (int i = 0; i < 60; i++) {
        cout << '-';
    }
    cout << endl;
}

void print_file(int index, int width) {
    cout << files[index];
    int nspace = width - files[index].size();
    for (int i = 0; i < nspace; i++) {
        cout.put(' ');
    }
}

// Status: Accepted
// Submit: 24471566
