#include<iostream>

using namespace std;

string sumofstring(string num){
    if(num.size() == 1){
        return num;
    }
    int sum = 0;
    for(auto ch : num){
        sum += ch - '0';
    }
    string temp  = to_string(sum);
    return sumofstring(temp);
}



int main(){
    string num;
    while(cin >> num , num!="0"){
        string ans = sumofstring(num);
        cout << ans << endl;
    }
}