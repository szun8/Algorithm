#include <iostream>
using namespace std;
int main(){
    int prices;
    cin>>prices;
    for (int i = 0; i < 9; i++)
    {
        int price;
        cin>>price;
        prices-=price;
    }
    cout<<prices;
    return 0;
}