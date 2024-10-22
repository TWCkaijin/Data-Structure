#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    string a,b;
    vector<char> v;
    while(cin >> a >> b){
        for(auto ch : a){
            if(b.find(ch) != b.npos){
                v.push_back(ch);
                b.erase(b.find(ch),1);
            }
        }
        sort(v.begin(),v.end());

        for(auto ch :v){
            cout << ch;
        }
        cout << endl;
        v.clear();
    }
}