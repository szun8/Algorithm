#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        float num;
        cin>>num;
        string what;
        cin>>what;
        cout<<fixed;
        cout.precision(4);
        if(what=="kg"){
            cout<<num*2.2046<<" lb\n";
        }
        else if(what=="l"){
            cout<<num*0.2642<<" g\n";
        }
        else if(what=="lb"){    //파운드
            cout<<num*0.4536<<" kg\n";
        }
        else if(what=="g"){     //갤런
            cout<<num*3.7854<<" l\n";
        }
    }
    return 0;
}