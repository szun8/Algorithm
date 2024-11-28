#include <iostream>
#include <algorithm>
using namespace std;

int n;

int CheckPalindromeLeft(string str){
    bool isMoved = false;
    int l = 0;
    int r = str.length()-1;

    while(l<=r){
        if(str[l] == str[r]){
            l++; r--;
        }else{
            if(isMoved) return 2; // 이미 유사 회문의 기회 1번을 소모한 상태

            l++;
            if(str[l] == str[r]){
                isMoved = true;
            }

            if(isMoved == false){
                r--; l--;
                if(str[l] == str[r])
                    isMoved = true;
            }

            if(isMoved == false) return 2; //왼쪽 오른쪽을 둘 다 건드려봐도 유사회문이 될 수 없는 경우
        }
    }

    return isMoved ? 1 : 0;
}

int CheckPalindromeRight(string str){
    bool isMoved = false;
    int l = 0;
    int r = str.length()-1;

    while(l<=r){
        if(str[l] == str[r]){
            l++; r--;
        }else{
            if(isMoved) return 2; // 이미 유사 회문의 기회 1번을 소모한 상태

            r--;
            if(str[l] == str[r]){
                isMoved = true;
            }

            if(isMoved == false){
                r++; l++;
                if(str[l] == str[r])
                    isMoved = true;
            }

            if(isMoved == false) return 2; //왼쪽 오른쪽을 둘 다 건드려봐도 유사회문이 될 수 없는 경우
        }
    }

    return isMoved ? 1 : 0;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=0; i<n; i++){
        string tmp;
        cin>>tmp;
        int leftAC = CheckPalindromeLeft(tmp);
        int rightAC = CheckPalindromeRight(tmp);

        if(leftAC == 0 || rightAC == 0) printf("0\n");
        else if(leftAC == 1 || rightAC == 1) printf("1\n");
        else printf("2\n");
    }
    return 0;
}