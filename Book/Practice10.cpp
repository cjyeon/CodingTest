// 연습문제 10: 중앙값 구하기
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct median
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    void insert(int data)
    {
        if (maxHeap.size() == 0)
        {
            maxHeap.push(data);
            return;
        }

        if (maxHeap.size() == minHeap.size())
        {
            if (data <= get())
                maxHeap.push(data);
            else 
                minHeap.push(data);
            return;
        }

        if (maxHeap.size() < minHeap.size())
        {
            if (data > get())
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(data);
            }
            else 
                maxHeap.push(data);
            return;
        }

        if (data < get()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(data);
        }
        else
            minHeap.push(data);
    }

    //중앙값 반환 함수
    double get()
    {
        if (maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0;
        if (maxHeap.size() < minHeap.size())
            return minHeap.top();
        return maxHeap.top();
    }
};

int main() 
{
    median median;

    median.insert(1);
    cout << "1 삽입 후 중앙값: " << median.get() << endl;

    median.insert(5);
    cout << "5 삽입 후 중앙값: " << median.get() << endl;

    median.insert(2);
    cout << "2 삽입 후 중앙값: " << median.get() << endl;

    median.insert(10);
    cout << "10 삽입 후 중앙값: " << median.get() << endl;

    median.insert(40);
    cout << "40 삽입 후 중앙값: " << median.get() << endl;
}
