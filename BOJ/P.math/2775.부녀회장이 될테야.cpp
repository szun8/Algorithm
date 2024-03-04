#include <iostream>
#include <vector>
using namespace std;

int main(){
    int input;
    cin >> input;
    for(int i =0; i<input;++i){
        int k,n;
        cin>>k>>n;  //k=층, n=호
        int ho=1;
        vector< vector<int> > apart(k+1,vector<int>(n));
        for(int i=0;i<n;i++){ // 0층 기초공사
            apart[0][i]=i+1;
        }
        for(int j=1;j<=k;j++){
            for(int i =0;i<n;i++){
                if(i==0) apart[j][i] = apart[j-1][i];
                else{
                    apart[j][i] = apart[j-1][i]+apart[j][i-1];
                }
            }
        }
        cout << apart[k][n-1]<<endl;
    }
    
    return 0;
}