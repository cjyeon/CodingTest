#include <iostream>
#include <unordered_map>
using namespace std;

class tiny_url
{
private:
    unordered_map<string, string> data;

public:
    pair<bool, string> findURL(const string& tiny) const
    {
        auto it = data.find(tiny);
        if (it == data.end())
            return make_pair(false, string());
        else return make_pair(true, it->second);
    }

    bool insertURL(const string& actual, const string& tiny)
    {
        auto result = findURL(tiny).first;
        if (result)
            return false;
        data[tiny] = actual;

        return true;
    }

    bool eraseURL(const string& tiny)
    {
        auto result = findURL(tiny).first;
        if (result)
        {
            data.erase(tiny);
            return true;
        }
        return false;
    }

    void print() const
    {
        for (const auto& i : data)
            cout << i.first << " -> " << i.second << endl;
        cout << endl;
    }
};

int main() {
    tiny_url tinyURL;

    if (tinyURL.insertURL("https://github.com/cjyeon", "https://mygithub"))
        cout << "github URL 등록 성공" << endl;
    else 
        cout << "github URL 등록 실패" << endl;

    if (tinyURL.insertURL("https://www.youtube.com/", "https://youtube"))
        cout << "youtube URL 등록 성공" << endl;
    else 
        cout << "youtube URL 등록 실패" << endl;

    auto url = tinyURL.findURL("https://mygithub");
	if (url.first)
		cout << "https://mygithub 원본 URL: " << url.second << endl;
	else
        cout << "https://mygithub 원본 URL을 찾을 수 없습니다." << endl;

	auto url2 = tinyURL.findURL("https://cpp_dojang");
	if (url2.first)
		cout << "https://cpp_dojang 원본 URL: " << url2.second << endl;
	else
		cout << "https://cpp_dojang 원본 URL을 찾을 수 없습니다." << endl;

	if (tinyURL.eraseURL("https://mygithub"))
		cout << "github URL 등록 해제" << endl;
	else
		cout << "github URL 등록 해제 실패" << endl;
    
    cout << "등록된 URL 목록: " << endl;
    tinyURL.print();

    return 0;
}