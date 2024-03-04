#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> cnt;

    for(int i=0;i<name.size();i++){
        cnt.insert(pair<string, int>(name[i], yearning[i]));
    }

    for (int i = 0; i < photo.size(); i++)
    {
        int nums = 0;
        for(int j=0; j<photo[i].size(); j++){   // 이름이 있으면 더해주고 아니면 다음으로 넘어간다.
            cnt.find(photo[i][j])!=cnt.end() ? nums+=cnt.find(photo[i][j])->second : nums+=0;
        }
        answer.push_back(nums);
    }
    
    return answer;
}

// 추가적으로 map 사용법 : <string, int>의 자료형이라면 map[string] = int의 대입 연산이 가능하다
// 고로 이름에 맞는 숫자를 지정해주는 방식이다.
// 문자는 first, 숫자는 second

int main(){
    vector<string> name;
    name = {"kali", "mari", "don"};

    vector<int> yearning;
    yearning = {11, 1, 55};

    vector<vector<string>> photo;
    photo = {{"kali", "mari", "don"}, {"pony", "tom", "teddy"}, {"con", "mona", "don"}};

    solution(name, yearning, photo);
    return 0;
}