#include <iostream>
#include <queue>
using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin>>n;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        string what;
        cin>>what;
        if (what=="push")
        {
            int num;
            cin>>num;
            q.push(num);
        }
        else if(what=="pop"){
            if(q.empty()) cout<<"-1\n";
            else{
                cout<<q.front()<<"\n";
                q.pop();
            }
        }
        else if(what=="size"){
            cout<<q.size()<<"\n";
        }
        else if(what=="empty"){
            if(q.empty()) cout<<"1\n";
            else cout<<"0\n";
        }
        else if(what=="front"){
            if(q.empty()) cout<<"-1\n";
            else{
                cout<<q.front()<<"\n";
            }
        }
        else if(what=="back"){
            if(q.empty()) cout<<"-1\n";
            else{
                cout<<q.back()<<"\n";
            }
        }
    }
    
    return 0;
}