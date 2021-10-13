#include <iostream>
#include <vector>
using namespace std;

int main(){
    int input;
    cin >> input;
    vector<float> average;
    for(int i = 0;i<input;++i){
        int student;
        cin>>student;

        vector<int> score;
        for(int i = 0 ;i<student;++i){
            int setScore;
            cin>>setScore;
            score.push_back(setScore);
        }

        float ave=0;
        for(int i =0;i<score.size();++i){
            ave+=score[i];
        }
        ave/=student;
        float num=0;\
        for(int i =0;i<student;++i){
            if(ave<score[i]) ++num;
        }
        average.push_back((num/student)*100);
    }
    for(int i =0;i<average.size();++i){
        cout<<fixed;
        cout.precision(3);
        cout<<average[i]<<"%"<<endl;
    }
    return 0;
}
