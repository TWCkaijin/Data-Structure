#include<iostream>
#include<vector>
#include<sstream>
#include<cmath>
using namespace std;

int main(){
    int x;
    string input;
    string enter;
    while(true){
        cin>>x;
        getline(cin,enter);
        getline(cin,input);
        if(cin.eof())return 0;
        vector<int> v;
        stringstream ss(input);
        int temp;
        while(ss>>temp){
            v.push_back(temp);
        }
        for(int i=0;i<v.size();i++){
            if(i==v.size()-1){
                v.erase(v.begin()+i);
            }else{
                v[i] = v[i] * (v.size()-1-i);
            }
        }
        long long int sum = 0;
        for(int i=0;i<v.size();i++){
            sum += v[i] * pow(x,v.size()-1-i); 
        }
        cout << sum << endl;
        v.clear();
    }
}