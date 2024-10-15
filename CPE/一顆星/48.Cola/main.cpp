#include<iostream>
using namespace std;

int step(int bts,int left){
    if(bts+left>=3)return bts + step((bts+left)/3,(bts+left)%3);
    else if(bts+left==2)return bts+1;
    else return bts;
}

int main(){
    int cases;
    while(cin >> cases){
        
        cout << step(cases,0) << endl;
    }
}