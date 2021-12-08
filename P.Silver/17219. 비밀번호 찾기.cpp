#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;
    map<string,string> site;
    for (int i = 0; i < n; i++)
    {
        string address, password;
        cin>>address>>password;

        site.insert(pair<string,string>(address,password));
    }

    for (int i = 0; i < m; i++)
    {
        string findSite;
        cin>>findSite;

        cout<<site.find(findSite)->second<<"\n";
    }
    return 0;
}