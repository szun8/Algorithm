#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> Word(n);

        for (int i = 0; i < n; i++) {
            cin>>Word[i];
        }
        sort(Word.begin(),Word.end());
        bool isOk = false;
        for (int i = 0; i < Word.size()-1; i++) {
            if(Word[i][0]==Word[i+1][0]){
                if(Word[i+1].substr(0, Word[i].size()) == Word[i]) {
                    printf("NO\n");
                    isOk = true;
                    break;
                }
            }
        }
        if(isOk == false) printf("YES\n");
    }
    return 0;
}