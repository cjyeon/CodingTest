// 연습문제 9: BST 구현
#include <iostream>
using namespace std;

//노드 구조체
struct node
{
    int data;
    node *left;
    node *right;
};

//bst 구조체
struct bst
{
    node *root = nullptr;

    node *find(int value)
    {
        return find_impl(root, value);
    }

private:
    node *find_impl(node *cur, int value)
    {
        if (!cur)
        {
            cout << endl;
            return NULL;
        }

        if (cur->data == value)
        {
            cout << value << "을(를) 찾았습니다." << endl;
            return cur;
        }

        //value값이 현재 노드 왼쪽에 있는 경우
        if (value < cur->data)
        {
            cout << cur->data << "에서 왼쪽으로 이동 ";
            return find_impl(cur->left, value);
        }

        //value값이 현재 노드 오른쪽에 있는 경우
        cout << cur->data << "에서 오른쪽으로 이동 ";
        return find_impl(cur->right, value);
    }

public:
    void insert(int value)
    {
        if (!root)
            root = new node{value, NULL, NULL};
        else
            insert_impl(root, value);
    }

private:
    void insert_impl(node *cur, int value)
    {
        if (value < cur->data)
        {
            if (!cur->left)
                cur->left = new node{value, NULL, NULL};
            else
                insert_impl(cur->left, value);
        }
        else
        {
            if (!cur->right)
                cur->right = new node{value, NULL, NULL};
            else
                insert_impl(cur->right, value);
        }
    }

public:
    void inorder()
    {
        inorder_impl(root);
    }

private:
    void inorder_impl(node *start)
    {
        if (!start)
            return;

        //BST는 중위 순회 활용
        inorder_impl(start->left);
        cout << start->data << " ";
        inorder_impl(start->right);
    }

public:
    //자식노드 찾는 함수
    node *successor(node *start)
    {
        auto cur = start->right;
        while (cur && cur->left)
            cur = cur->left;
        return cur;
    }

    void deleteValue(int value)
    {
        root = delete_impl(root, value);
    }

private:
    //원소 삭제
    node* delete_impl(node *start, int value)
    {
        if (!start)
            return NULL;

        if (value < start->data)
            start->left = delete_impl(start->left, value);
        else if (value > start->data)
            start->right = delete_impl(start->right, value);
        else
        {
            //자식노드 없거나, 왼쪽 자식노드만 없는 경우
            if (!start->left)
            {
                auto tmp = start->right;
                delete start;
                return tmp;
            }

            //오른쪽 자식노드만 없는 경우
            if (!start->right)
            {
                auto tmp = start->left;
                delete start;
                return tmp;
            }

            //자식노드 둘 다 있는 경우
            auto succNode = successor(start);
            start->data = succNode->data;

            //오른쪽 서브트리에서 자식찾아서 삭제
            start->right = delete_impl(start->right, succNode->data);
        }

        return start;
    }
};

int main() {
    bst tree;
    tree.insert(12);
    tree.insert(10);
    tree.insert(20);
    tree.insert(8);
    tree.insert(11);
    tree.insert(15);
    tree.insert(28);
    tree.insert(4);
    tree.insert(2);

    cout << "중위 순회: ";
    tree.inorder(); 
    cout << endl;

    tree.deleteValue(12);
    cout << "12 삭제한 후 중위 순회: ";
    tree.inorder();
    cout << endl;

    if (tree.find(12))
        cout << "원소 12는 트리에 있습니다." << endl;
    else
        cout << "원소 12는 트리에 없습니다." << endl;
}