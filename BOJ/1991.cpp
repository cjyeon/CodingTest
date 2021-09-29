#include <iostream>
using namespace std;

struct tree_node
{
    char left;
    char right;
};

struct tree_node node[80];

//전위 순회
void preOrder(char root) {
    if (root == '.') return;
    else {
        cout << root;
        preOrder(node[root].left);
        preOrder(node[root].right);
    }
}

//중위 순회
void inOrder(char root) {
    if (root == '.') return;
    else {
        inOrder(node[root].left);
        cout << root;
        inOrder(node[root].right);
    }
}

//후위 순회
void postOrder(char root) {
    if (root == '.') return;
    else {
        postOrder(node[root].left);
        postOrder(node[root].right);
        cout << root;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int num;
    char c1, c2, c3;

    cin >> num;

    while(num--) {
        cin >> c1 >> c2 >> c3;
        node[c1].left = c2;
        node[c1].right = c3;
    }

    preOrder('A');
    cout << '\n';
    inOrder('A');
    cout << '\n';
    postOrder('A');
}