#include <iostream>
#include <stack>
using namespace std;
int main(){
    string str;
    cin>>str;
    int n;
    cin>>n;

    stack<char> save;
    for (int i = 0; i < str.size(); i++)
    {
        save.push(str[i]);
    }
    
    stack<char> temp;
    for (int i = 0; i < n; i++)
    {
        char what;
        cin>>what;
        if(what == 'L' && !save.empty()){
            temp.push(save.top());
            save.pop();
        }
        else if(what == 'D' && !temp.empty()){
            save.push(temp.top());
            temp.pop();
        }
        else if(what == 'B' && !save.empty()){
            save.pop();
        }
        else if(what == 'P'){
            char a;
            cin>>a;
            save.push(a);
        }
    }
    while (!temp.empty())
    {
        save.push(temp.top());
        temp.pop();
    }
    
    while(!save.empty()){
        temp.push(save.top());
        save.pop();
    }

    while(!temp.empty()){
        cout<<temp.top();
        temp.pop();
    }
    return 0;
}