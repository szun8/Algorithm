#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; 
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int r=1;
        bool isIn= true;    // size가 0인데 D를 하는 경우
        string what, arr;
        int size;
        deque<int> dq;
        cin>>what>>size>>arr;
        for (int j = 1; j < arr.size(); j++)
        {
            if(arr.size()==2) break;
            string snum = "";
            if(isdigit(arr[j])!=0){
                while (isdigit(arr[j])!=0)
                {
                    snum+=arr[j];
                    ++j;
                }
            }
            int num = stoi(snum);
            dq.push_back(num);
        }
        

        for (int j = 0; j < what.size(); j++)
        {
            if(what[j]=='R') {
                r*=-1;
            }
            else if(what[j]=='D'){
                if(dq.size()==0) {
                    isIn= false;
                    break;
                }
                else{
                    if(r==1){
                        dq.pop_front();
                    }
                    else{
                        dq.pop_back();
                    }
                }
            }
        }

        if(isIn) {
            cout<<"[";
            if(dq.size()==0){
                cout<<"]\n";
            }
            else if(r==1){
                for (int i = 0; i < dq.size()-1; i++)
                {
                    cout<<dq[i]<<",";
                }
                cout<<dq[dq.size()-1]<<"]\n";
            }
            else if(r==-1){
                for (int i = dq.size()-1; i > 0; i--)
                {
                    cout<<dq[i]<<",";
                }
                cout<<dq[0]<<"]\n";
            }
        }
        else{
            cout<<"error\n";
        }
    }
    return 0;
}