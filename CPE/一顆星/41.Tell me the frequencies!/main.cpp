#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;




int main(){
    string total;
    
    while(getline(cin,total)){

        map<char,int> charset;
        for(char ch:total){
            if(ch<=127 && ch>=32){
                charset[ch]+=1;
            }
            
        }


        vector<pair<char,int>> tempvec(charset.begin(),charset.end());
        sort(tempvec.begin(),tempvec.end(),[](pair<char,int> a, pair<char,int> b){
            if(a.second!=b.second)return a.second<b.second;
            else return a.first>b.first;
        });
        

        for(pair<char,int> cs:tempvec){
            cout << (int)(cs.first) << " "<<cs.second << endl;
        }
        charset.clear();
        tempvec.clear();
    }
    
}