#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<long long> nums;
    vector<char> exp, real_exp;
    string tmp = "";
    
    for(char c : expression) {
        if(c == '*' || c == '+' || c == '-') {
            nums.push_back(stoi(tmp));
            tmp = "";
            real_exp.push_back(c);
            if(find(exp.begin(), exp.end(), c) == exp.end())
                exp.push_back(c);
        }
        else tmp += c;
    }
    nums.push_back(stoi(tmp));

    //next_permutation 위해 정렬
    sort(exp.begin(), exp.end());

    do{
        vector<long long> tmp_nums(nums);
        vector<char> tmp_realexp(real_exp);

		for(int i = 0; i < exp.size(); i++) 
        {
            for (int j = 0; j < tmp_realexp.size(); j++)
            {
                if(tmp_realexp[j] == exp[i]) {
                    if (tmp_realexp[j] == '*')
                        tmp_nums[j] = tmp_nums[j] * tmp_nums[j+1];
                    else if (tmp_realexp[j] == '+')
                        tmp_nums[j] = tmp_nums[j] + tmp_nums[j+1];
                    else if (tmp_realexp[j] == '-')
                        tmp_nums[j] = tmp_nums[j] - tmp_nums[j+1];
                        
                    tmp_nums.erase(tmp_nums.begin() + j + 1);
                    tmp_realexp.erase(tmp_realexp.begin() + j);
                    j--;
                }
            }
		}
        if(answer < abs(tmp_nums[0])) answer = abs(tmp_nums[0]);

	} while (next_permutation(exp.begin(), exp.end()));

    return answer;
}