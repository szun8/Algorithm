#include <iostream>
#include <vector>
using namespace std;
int main(){
    int count = 1;
    while (true)
    {
        int n;
        cin>>n;
        cin.ignore();

        if(n==0) break;

        vector<pair<int, string> > names;
        for (int i = 0; i < n; i++)
        {
            // 여학생 이름 읿력
            string name;
            getline(cin, name);
            names.push_back(pair<int, string>(i+1,name));
            // 해당 여학생의 순번과 이름을 넣어주기
        }

        vector<int> girls;
        for (int i = 0; i < 2*n-1; i++)
        {
            int num;
            char type;
            cin >> num >> type;

            int size=0;
            bool ishere = false;
            while(size<girls.size()){
                if(girls[size]==num){
                    // 이미 등록되어 있는 친구라면, 돌려주는 순번이니까 없애주기
                    girls.erase(girls.begin()+size);
                    ishere = true;
                    break;
                }
                ++size;
            }

            if(ishere==false){
                // 등록이 안된 학생이라면, 등록해주기(압수절차)
                girls.push_back(num);
            }
        }
        for (int i = 0; i < names.size(); i++)
        {
            if(names[i].first==girls[0]){
                cout<<count<<" "<<names[i].second<<"\n";
            }
        }
        ++count;
    }
    return 0;
}