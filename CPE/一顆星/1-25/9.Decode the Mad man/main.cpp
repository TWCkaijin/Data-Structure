#include<iostream>
#include<algorithm>
using namespace std;


int main(){
    string str;
    string temp[] = {"`1234567890-=","qwertyuiop[]\\" , "asdfghjkl;'" , "zxcvbnm,./"};
    int strrow = 4;
    while(getline(cin,str)){
        
        for(auto ch : str){
            if(ch == ' ' || ch == '\n'){
                cout << ch;
                continue;
            }
            for(int i=0;i<strrow;i++){
                if(find(temp[i].begin(),temp[i].end(),ch) != temp[i].end()){
                    cout << temp[i][temp[i].find(ch)-2];
                }
            }
        }
        cout << endl;
    }
}