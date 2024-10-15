#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

map<char,int> list;


void count(string x){
    for(auto ch : x){
        if((ch >= 'A' && ch <= 'Z') && list.find(ch)==list.end() ){;
            list[ch] = 1;
        }else if((ch >= 'a' && ch <= 'z') && list.find(ch-32)==list.end() ){
            list[ch-32] = 1;
        }else if(ch >= 'A' && ch <= 'Z'){
            list[ch]++;
        }else if(ch >= 'a' && ch <= 'z'){
            list[ch-32]++;
        }
    }
}

int main(){
    int n;
    cin >> n;
    string s;
    for(int i=0;i<=n;i++){
        getline(cin,s);
        count(s);
    }

    vector<pair<char,int>> v(list.begin(),list.end());
    sort(v.begin(),v.end(),[](pair<char,int> a,pair<char,int> b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second > b.second;
    });

    for(auto i = v.begin();i != v.end();i++){
        cout << i->first << " " << i->second << endl;
    }
}