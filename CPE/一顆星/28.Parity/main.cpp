#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    while(cin >>n , n!=0){
        int ntemp = n;
        vector<int> v;
        while(n){
            int temp = n%2;
            v.push_back(temp);
            n -= temp;
            n/=2;
        }

        count(v.begin(),v.end(),1);
        cout <<"The parity of "<< ntemp <<" is " <<count(v.begin(),v.end(),1)<< " (mod 2)."<<endl;
    }
}