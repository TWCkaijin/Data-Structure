#include<iostream>

using namespace std;

int main(){
    string input;
    bool flag = true;
    while(getline(cin,input)){
        for(auto ch : input){
            if(ch == '"' && flag){
                cout << "``";
                flag = false;
            }else if(ch == '"' && !flag){
                cout << "''";
                flag = true;
            }else{
                cout << ch;
            }
        }
        cout << endl;
    }
}