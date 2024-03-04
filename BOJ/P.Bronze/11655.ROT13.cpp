#include <iostream>
using namespace std;
int main(){
    string rot;
    getline(cin,rot);

    for (int i = 0; i < rot.size(); i++)
    {
        if(rot[i]>=65 && rot[i]<=90) { //대문자
            rot[i] = (rot[i]+13);
            if(rot[i]>90) rot[i]-=26;
        }
        else if(rot[i]>=97 && rot[i]<=122){ //소문자
            if(rot[i]+13>122) rot[i]-=13;
            else{
                rot[i] = (rot[i]+13);
            }
        }
        //   공백이거나 알파벳 이외의 문자는 다음 문자로 넘어가기
    }
    
    cout<< rot;
    return 0;
}