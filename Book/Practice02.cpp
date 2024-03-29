// 연습문제 2: 데이터 저장 컨테이너
#include <array>
#include <iostream>
#include <type_traits>
using namespace std;

template<typename ... Args>
auto build_array(Args&&... args) -> array<typename common_type<Args...>::type, sizeof...(args)> 
{
    using commonType = typename common_type<Args...>::type;
    return {forward<commonType>((Args&&)args)...};
}

int main() {
    auto data = build_array(1, 0u, 'a', 3.2f, false);

    for (auto i : data)
    {
        cout << i << " ";
    }
    cout << endl;
}