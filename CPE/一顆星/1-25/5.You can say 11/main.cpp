#include<iostream>
using namespace std;

bool mult(string n){
    int odd=0, even=0;
    for(int i=0;i<n.size();i++){
        if(i%2==0){
            even += n[i]-'0';
        }else{
            odd += n[i]-'0';
        }
    }
    return (odd-even)%11==0;
}


int main(){
    string num;
    while(cin >> num){
        if(num=="0"){
            break;
        }
        if(mult(num)){
            cout << num << " is a multiple of 11." << endl;
        }else{
            cout << num << " is not a multiple of 11." << endl;
        }
    }
}