#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector <string> v;
    string temp;
    int maxlen = 0;
    while(getline(cin,temp)){
        v.push_back(temp);
        maxlen = max(maxlen,(int)temp.size());
    }


    
    for(int j=0;j<maxlen;j++){
        for(int i=v.size()-1;i>=0 ;i--){
            if(v[i].length() > j){
                cout << v[i][j];

            }else{
                cout << " ";
            }
        }
        cout << endl;
    }

}