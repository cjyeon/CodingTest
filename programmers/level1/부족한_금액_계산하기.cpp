using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    long long sum = (long long)(count * (count + 1) / 2) * price;

    if(sum > money) answer = sum - money;
    return answer;
}