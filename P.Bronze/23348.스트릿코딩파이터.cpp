#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int A,B,C,club;
    cin >> A >> B >> C >> club; 
    vector< vector<int> > score(3*club, vector<int>(3));
    vector<int> clubScore(club, 0);

    int j = 0, count = 0;
    for(int i=0; i<club*3; i++) {
        cin >> score[i][0] >> score[i][1] >> score[i][2];
        if(count<3){
            clubScore[j] += (score[i][0]*A + score[i][1]*B + score[i][2]*C);
            count++;
            if(count == 3){
                count=0;
                j++;
            }
        }
    }
    int max = *max_element(clubScore.begin(),clubScore.end());
    cout<<max;
    return 0;
}