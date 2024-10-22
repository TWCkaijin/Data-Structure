#include<iostream>

using namespace std;

int main(){
    int cases;
    cin >> cases;
    int s,d;
    for(int i=0;i<cases;i++){
        cin >> s >> d;
        if(s<d || (s+d)%2!=0){
            cout << "impossible" << endl;
        }else{
            cout << (s+d)/2 << " " << (s-d)/2 << endl;
        }
    }
}