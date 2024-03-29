// 연습문제 7: 조직도 구조 구현
#include <iostream>
#include <queue>
using namespace std;

struct node
{
    string position;
    node* first;
    node* second;
};

struct org_tree
{
    node* root;

    //루트 노드 생성
    static org_tree create_org_structure(const string& pos)
    {
        org_tree tree;
        tree.root = new node{pos, NULL, NULL};
        return tree;
    }

    static node* find(node* root, const string& value)
    {
        if(root == NULL) return NULL;

        if(root->position == value) return root;

        auto firstFound = org_tree::find(root->first, value);

        if (firstFound != NULL) return firstFound;

        return org_tree::find(root->second, value);
    }

    bool addSubordinate(const string& manager, const string& subordinate)
    {
        auto managerNode = org_tree::find(root, manager);

        if (!managerNode)
        {
            cout << manager << "을(를) 찾을 수 없습니다. " << endl;
            return false;
        }
        
        if (managerNode->first && managerNode->second)
        {
            cout << manager << " 아래에 " << subordinate << "을(를) 추가할 수 없습니다." << endl;
            return false;
        }

        if (!managerNode->first)
            managerNode->first = new node{subordinate, NULL, NULL};
        else
            managerNode->second = new node{subordinate, NULL, NULL};
        
        cout << manager << " 아래에 " << subordinate << "을(를) 추가했습니다." << endl;

        return true;
    }
};

int main()
{
    auto tree = org_tree::create_org_structure("CEO");

    tree.addSubordinate("CEO", "부사장");
    tree.addSubordinate("부사장", "IT부장");
    tree.addSubordinate("부사장", "마케팅부장");
    tree.addSubordinate("IT부장", "보안팀장");
    tree.addSubordinate("IT부장", "앱개발팀장");
    tree.addSubordinate("마케팅부장", "홍보팀장");
    tree.addSubordinate("마케팅부장", "물류팀장");
    tree.addSubordinate("부사장", "재무부장");
}