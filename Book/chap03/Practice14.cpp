// 연습문제 14: 체이닝 사용한 해시테이블(충돌 해결)
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

using uint = unsigned int;

class hash_map
{
    vector<list<int, int>> data;
public:
    hash_map(size_t n)
    {
        data.resize(n);
    }

    void insert(uint value)
    {
        int n = data.size();
        data[value % n].push_back(value);
        cout << value << "을(를) 삽입했습니다." << endl;
    }
    
    //연결리스트에서 검색
    bool find(uint value)
    {
        int n = data.size();
        auto& entries = data[value % n];
        return std::find(entries.begin(), entries.end(), value) != entries.end();
    }

    void erase(uint value)
    {
        int n = data.size();
        auto& entries = data[value % n];
        auto it = std::find(entries.begin(), entries.end(), value);

        if (it != entries.end())
        {
            entries.erase(it);
            cout << value << "을(를) 삭제했습니다." << endl;
        }
        
    }
};


int main() {
    hash_map map(7);

    auto print = [&](uint value) {
        if (map.find(value))
            cout << "해시 맵에서 " << value << "을(를) 찾았습니다.";
        else
            cout << "해시 맵에서 " << value << "을(를) 찾지 못했습니다.";
        cout << endl;
    };

    map.insert(2);
    map.insert(25);
    map.insert(10);
    map.insert(100);
    map.insert(55);

    print(100);
    print(2);

    map.erase(2);

    return 0;
}