#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;                      // 한줄에 몇개?
    string password;
    cin>>n>>password;
    int c = password.size()/n;  // 몇줄?
    int cnt = 0;
    vector<vector<char> > decode(c,vector<char>(n));
    for (int i = 0; i < c; i++) {
        if(i%2==0){             // 왼->오
            for (int j = 0; j < n; j++){
                decode[i][j]=password[cnt++];
            }
        }
        else{                   // 오->왼
            for (int j = n-1; j >= 0; j--){
                decode[i][j]=password[cnt++];
            }
        }
    }
    
    for (int i = 0; i < n; i++) {   // 출력
        for (int j = 0; j < c; j++) {
            cout<<decode[j][i];
        }
    }
    return 0;
}
