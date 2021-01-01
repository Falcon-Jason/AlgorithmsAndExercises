#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

struct tree {
    int type;
    tree *next[4];
} trees[5000];
tree *ptrees = trees;

#define NEW_NODE() (ptrees++)
#define FREE_TREES() (ptrees = trees)

tree *read_tree();
void add_tree(tree *s, tree *t);
void print_tree(tree *t);
int tree_count(tree *t, int sz);

int main() {
#ifndef ONLINE_JUDGE
    freopen("tmp-in", "r", stdin);
    freopen("tmp-out", "w", stdout);
#endif
    int count;
    cin >> count;
    cin.get();
    for (int i = 0; i < count; i++) {
        tree *s = read_tree();
        tree *t = read_tree();
        // print_tree(s);
        // cout << endl;
        // print_tree(t);
        // cout << endl;
        add_tree(s, t);
        cout << "There are " << tree_count(s, 32 * 32) << " black pixels."
             << endl;
        FREE_TREES();
    }
}

tree *parse_tree();
char line[4096];
char *pline;
tree *read_tree() {
    fgets(line, 4096, stdin);
    pline = line;
    return parse_tree();
}

tree *parse_tree() {
    tree *node = NEW_NODE();
    node->type = *(pline++);
    if (node->type == 'p') {
        for (int i = 0; i < 4; i++) {
            node->next[i] = parse_tree();
        }
    }
    return node;
}

void add_tree(tree *s, tree *t) {
    if (s->type == 'f' || t->type == 'e') {
        return;
    }
    if (s->type == 'e') {
        *s = *t;
        return;
    }
    if (t->type == 'f') {
        s->type = 'f';
        return;
    }

    for (int i = 0; i < 4; i++) {
        add_tree(s->next[i], t->next[i]);
    }
}

void print_tree(tree *t) {
    cout << (char)t->type;
    if (t->type == 'p') {
        cout << "(";
        for (int i = 0; i < 4; i++) {
            print_tree(t->next[i]);
        }
        cout << ")";
    }
}

int tree_count(tree *t, int sz) {
    if (t->type == 'f')
        return sz;
    if (t->type == 'e')
        return 0;
    int res = 0;
    for (int i = 0; i < 4; i++) {
        res += tree_count(t->next[i], sz / 4);
    }
    return res;
}

// Status: Accepted
// Submit: 24521141