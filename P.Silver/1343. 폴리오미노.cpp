#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    string what;
    cin>>what;
    int count = 0;
    for (int i = 0; i < what.size(); i++)
    {
        if(what[i]=='X') ++count;
        else if (what[i]=='.'){
            if(count == 0) continue;
            else if(count%2==1) {
                // 홀수라면
                cout<<"-1";
                return 0;
            }
            else if(count%4==0){
                int n = count/4;
                while(n>0){
                    int iter = what.find_first_of('X');
                    what.replace(what.begin()+iter,what.begin()+iter+4,"AAAA");
                    --n;
                }
            }
            else if(count%2==0 && count>=4){
                int n = count/4;
                while(n>0){
                    int iter = what.find_first_of('X');
                    what.replace(what.begin()+iter,what.begin()+iter+4,"AAAA");
                    --n;
                }
                int iter2 = what.find_first_of('X');
                what.replace(what.begin()+iter2,what.begin()+iter2+2,"BB");
            }
            else{
                int iter2 = what.find_first_of('X');
                what.replace(what.begin()+iter2,what.begin()+iter2+2,"BB");
            }
            count = 0;
        }
    }
    if(count>0){
        if(count%2==1) {
            // 홀수라면
            cout<<"-1";
            return 0;
        }
        else if(count%4==0){
            int n = count/4;
            
        }
        else if(count%2==0 && count>=4){
            int n = count/4;
            while(n>0){
                int iter = what.find_first_of('X');
                what.replace(what.begin()+iter,what.begin()+iter+4,"AAAA");
                --n;
            }
            int iter2 = what.find_first_of('X');
            what.replace(what.begin()+iter2,what.begin()+iter2+2,"BB");
        }
        else{
            int iter2 = what.find_first_of('X');
            what.replace(what.begin()+iter2,what.begin()+iter2+2,"BB");
        }
    }

    cout<<what;
    return 0;
}