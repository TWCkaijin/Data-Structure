#include<iostream>

using namespace std;


int main(){
    unsigned long long int x,y;
    while(true){
        cin >> x ;
        if(x==EOF){
            break;
        }
        cin >> y;

        cout << y-x << endl;

    }
}