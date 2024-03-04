#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 시간초과 방지
    int n,num;;
    cin >> n;
    int arr[10001]={0,};

    for(int i=0;i<n;++i){
        cin>>num;
        ++arr[num];
    }
    
    for(int i = 1;i<10001;i++){
        for(int j =0;j<arr[i];j++){
            if(arr[i]!=0)
            // 출력초과가 나므로 해당 조건 걸어주기...
                printf("%d\n",i);
        }
    }
    return 0;
}