#include <bits/stdc++.h>
using namespace std;
struct node {
    int num;
    int rchild = -1;
    int lchild = -1;
};
vector tree;
void add(int n, int from) {
    node newnode;
    newnode.num = n;
    if (tree.empty()) {
        tree.push_back(newnode);
    } else {
        if (n < tree[from].num) {
            if (tree[from].lchild == -1) {
                tree.push_back(newnode);
                tree[from].lchild = tree.size() - 1;
            } else {
                add(n, tree[from].lchild);
            }
        } else {
            if (tree[from].rchild == -1) {
                tree.push_back(newnode);
                tree[from].rchild = tree.size() - 1;
            } else {
                add(n, tree[from].rchild);
            }
        }
    }
}
void pass(int index) {
    if (tree[index].lchild != -1) {
        pass(tree[index].lchild);
    }
    if (tree[index].rchild != -1) {
        pass(tree[index].rchild);
    }
    cout << tree[index].num << endl;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        add(j, 0);
    }
    pass(0);
}