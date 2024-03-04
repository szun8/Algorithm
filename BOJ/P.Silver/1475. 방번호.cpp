#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string number;
    cin>>number;
    
    vector<int> door (10,0);

    for (int i = 0; i < number.size(); i++)
    {
        if(number[i]=='6' && door[number[i]-45] < door[number[i]-48]){ // [9] != [6]
            door[number[i]-45]++;   // [9]++;
        }
        else if(number[i]=='9' && door[number[i]-48] > door[number[i]-51]){ // [9] != [6]
            door[number[i]-51]++;   // [6]++;
        }
        else{
            ++door[number[i]-48]; // 미사용이었으면 사용처리!
        }
    }
    int max = *max_element(door.begin(),door.end());
    cout<<max;
    return 0;
}