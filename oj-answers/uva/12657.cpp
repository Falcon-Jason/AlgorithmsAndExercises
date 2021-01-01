#include <algorithm>
#include <iostream>

struct node {
    node *left;
    node *right;
} nodes[100100];

inline node *init_node(int size);
void move(int pos, node *s, node *t);
void swap(node *p, node *q);
long long odd_sum(int reversed, node *tail);

int main() {
    using namespace std;
    int size, ncmd;
    int case_id = 1;
    while (cin >> size >> ncmd) {
        int op, x, y;
        bool reversed = false;
        node *tail = init_node(size);
        for (int i = 0; i < ncmd; i++) {
            cin >> op;
            switch (--op) {
                case 0:
                case 1:
                    cin >> x >> y;
                    move(op ^ reversed, nodes + x, nodes + y);
                    break;
                case 2:
                    cin >> x >> y;
                    swap(nodes + x, nodes + y);
                    break;
                case 3:
                    reversed = !reversed;
                    break;
            }
        }
        cout << "Case " << case_id++ << ": " << odd_sum(reversed, tail) << endl;
    }
}

inline void connect(node *p, node *q);
inline void insert(node *s, node *t);

inline node *init_node(int size) {
    nodes[0].left = nullptr;
    for (int i = 1; i <= size + 1; i++) {
        connect(&nodes[i - 1], &nodes[i]);
    }
    nodes[size + 1].right = nullptr;
    return &nodes[size + 1];
}

void move(int pos, node *s, node *t) {  // move s to the left(pos=0)/right(pos=1) to t
    if (pos == 0 && t->left != s) {
        connect(s->left, s->right);
        insert(s, t->left);
    } else if (pos == 1 && t->right != s) {
        connect(s->left, s->right);
        insert(s, t);
    }
}

void swap(node *p, node *q) {
    if (p->left != q && p->right != q) {
        node *ql = q->left;
        connect(p->left, p->right);
        connect(q->left, q->right);
        insert(q, p->left);
        insert(p, ql);
        return;
    } else {
        if (p->left == q) {
            std::swap(p, q);
        }
        connect(p->left, q);
        connect(p, q->right);
        connect(q, p);
    }
}

long long odd_sum(int reversed, node *tail) {
    long long sum = 0;
    bool is_odd = true;
    using namespace std;
    if (!reversed) {
        for (node *i = nodes[0].right; i != tail; i = i->right) {
            sum += (is_odd) ? i - nodes : 0;
            is_odd = !is_odd;
        }
    } else {
        for (node *i = tail->left; i != &nodes[0]; i = i->left) {
            sum += (is_odd) ? i - nodes : 0;
            is_odd = !is_odd;
        }
    }
    return sum;
}

inline void connect(node *p, node *q) {
    q->left = p;
    p->right = q;
}

inline void insert(node *s, node *t) {  // insert s to the right to t
    connect(s, t->right);
    connect(t, s);
}

// Status: Accepted
// Submit: 24470597