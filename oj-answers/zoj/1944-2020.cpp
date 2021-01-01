#include <cstdio>
#include <cstring>

void compute_postorder(char *preorder, char *inorder, int size);

int main() {
    char preorder[32];
    char inorder[32];

    while (scanf("%32s %32s", preorder, inorder) == 2) {
        compute_postorder(preorder, inorder, strlen(preorder));
        putchar('\n');
    }
}

void compute_postorder(char *preorder, char *inorder, int size) {
    if (size == 1) {
        putchar(*preorder);
        return;
    }
    if (size == 0)
        return;

    int root = strchr(inorder, *preorder) - inorder;

    compute_postorder(preorder + 1, inorder, root);
    compute_postorder(preorder + 1 + root, inorder + 1 + root, size - root - 1);
    putchar(inorder[root]);
}