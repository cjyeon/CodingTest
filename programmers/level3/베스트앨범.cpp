#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> sum;
    map<string, map<int, int>> songs;

    for(int i = 0; i < genres.size(); i++) {
        songs[genres[i]][i] = plays[i];
        sum[genres[i]] += plays[i];
    }

    while (!sum.empty())
    {
        string genre;
        int max = 0;

        for (auto s : sum)
        {
            if(max < s.second) {
                max = s.second;
                genre = s.first;
            }
        }

        for (int i = 0; i < 2; i++)
        {
            int index = -1;
            max = 0;

            for (auto song : songs[genre])
            {
                if (max < song.second)
                {
                    max = song.second;
                    index = song.first;
                }
            }

            if (index != -1) {
                answer.push_back(index);
                songs[genre].erase(index);
            }
            else break;
        }
        sum.erase(genre);
    }

    return answer;
}