#include<iostream>
#include<map>
using namespace std;


pair<bool,int> camp(string num, int rec=1){
    long int sum = 0;
    for(char c:num){
        sum += c-'0';
    }

    if(sum==9)return {true,rec};
    if(num.length()==1 && sum!=9)return {false,0};


    return camp(to_string(sum),rec+1);
}

//999999999999999999999 is a multiple of 9 and has 9-degree 3.
int main(){
    string cases;
    while(cin>>cases,cases!="0"){
        pair<bool,int> flag = camp(cases);
        if(flag.first)cout <<  cases << " is a multiple of 9 and has 9-degree " << flag.second << "."<< endl;
        else cout <<  cases << " is not a multiple of 9." << endl;
    }
}