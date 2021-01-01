#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
    string word;
    stack<string> words;

    while (cin >> word){
        words.push(word);
    }

    while(!words.empty()){
        word = words.top();
        words.pop();
        cout << word;
        if(!words.empty())
            cout << ' ';
    }
    return 0;
}