#include<iostream>
#include<iomanip>
#include<cmath>
#define game 40

using namespace std;




int main(){
    int per;
    cin >> per;
    for(int i=0;i<per;i++){
        int players;
        double prob;
        int target;
        cin >> players >> prob >> target;
        cout << fixed << setprecision(4);
        //cout <<prob << "  ||  "<<pow(1-prob,target-1)<< "  ||  "<<((1)/1-pow(1-prob,players))<< endl; 
        cout <<prob*pow(1-prob,target-1)*((1)/(1-pow(1-prob,players)))<< endl; 
        
        
    }
}