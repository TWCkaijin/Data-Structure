#include<iostream>

using namespace std;


int gcd(int a,int b){
    if(a==0)return b;
    if(b==0)return a;
    return gcd(b,a%b); 
}



int main(){
    
    int N  = 0;
    while(cin >> N, N!=0){
        long long int G=0;
        for(int i=1;i<N;i++){
            for(int j=i+1;j<=N;j++){
                G+=gcd(i,j);
            }    
        }
        cout << G << endl;
    }
    
}
