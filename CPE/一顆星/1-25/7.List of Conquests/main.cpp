#include<iostream>
#include<map>
using namespace std;



void addc(map<string,int> &countries,string name){
    if(countries.find(name) == countries.end()){
        countries[name] = 1;
    }else{
        countries[name]++;
    }
}

int main(){
    int roles;
    cin >> roles;

    map<string,int> countries;

    for(int i=0;i<roles;i++){
        string country;
        string name;
        cin >> country;
        getline(cin,name);
        addc(countries,country);
    }

    for(auto i = countries.begin();i != countries.end();i++){
        cout << i->first << " " << i->second << endl;
    }
    countries.clear();
}