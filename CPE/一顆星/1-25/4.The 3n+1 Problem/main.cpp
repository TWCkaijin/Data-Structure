#include<iostream>
using namespace std;

int func(int n, int count=1){
    if(n==1){
        return count;
    }else if(n%2==0){
        return func(n/2, count+1);
    }else if(n%2!=0){
        return func(3*n+1, count+1);
    }
}


int main(){
    int x ,y ,low , high;
    while(cin >> x >>y){
        int max=0;
        int num=0;

        if(x<y){
            low = x;
            high = y;
        }else{
            low = y;
            high = x;
        }

        for(int i= low;i<= high;i++){
            num = func(i);
            max = num>max?num:max;
        }
        cout << x <<" "<< y <<" "<< max << endl;
    }
}