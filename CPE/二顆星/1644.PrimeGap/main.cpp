#include<iostream>
#include<cmath>
using namespace std;


bool isprime(int N){
    int sq = sqrt(N);
    if(N<2 || (!(N&1) && N!=2))
        return false;
    for(int i=3; i<=sq; i+=2){
        if(!(N%i))
            return false;
    }
    return true;
}

int find_gap(int num){
    int count = 1;
    int temp = num;
    if(!isprime(num))count++;
    else return 0;
    while(!isprime(++temp)){
        count++;
    }
    temp = num;
    while(!isprime(--temp)){
        count++;
    }
    return count;
}


int main(){
    int cases;
    while(cin >> cases , cases !=0){
        int c = find_gap(cases);
        cout << c << endl;
    }
}