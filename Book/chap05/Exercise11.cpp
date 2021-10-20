#include <iostream>
#include <algorithm>
#include <list>
#include <random>
using namespace std;

struct task
{
    int id;
    unsigned start;
    unsigned end;
};

auto initial_task(int num, int max)
{
    // 시작 종료 시간은 임의의 정수로 설정
    random_device rd;
    mt19937 rand(rd());
    uniform_int_distribution<mt19937::result_type> uniform_dist(1, max);
    list<task> tasks;

    for (int i = 0; i < num; i++)
    {
        auto time_start = uniform_dist(rand);
        auto time_end = uniform_dist(rand);

        if (time_start == time_end)
            time_end++;
        if (time_start > time_end)
            swap(time_start, time_end);

        tasks.push_back({i + 1, time_start, time_end});
    }
    return tasks;
}

auto scheduling(list<task> tasks)
{
    tasks.sort([](const auto &a, const auto &b)
               { return a.end < b.end; });

    for (auto now = tasks.begin(); now != tasks.end(); now++)
    {
        auto next_task = next(now, 1);

        while (next_task != tasks.end() && next_task->start < now->end)
        {
            next_task = tasks.erase(next_task);
        }
    }
    return tasks;
}

int main()
{
    int num = 10;
    int max = 20;

    auto tasks = initial_task(num, max);
    cout << "[전체 작업]" << '\n';

    for (auto t : tasks)
        cout << "[" << t.id << "] " << t.start << " -> " << t.end << '\n';

    cout << '\n';

    auto tasks_result = scheduling(tasks);
    cout << "[스케줄 조정한 작업]" << '\n';
    for (auto t : tasks_result)
        cout << "[" << t.id << "] " << t.start << " -> " << t.end << '\n';
    
    return 0;
}