#include<iostream>
#include<algorithm>
using namespace std;





int main(){
    int cases;
    while(cin>>cases, cases!=0){
        int n=2,t=1,w=3;
        for(int i=0;i<cases;i++){
            string cmd;
            cin>>cmd;
            int temp;
            if(cmd=="north"){
                temp = n;
                n = t;
                t = 7-temp;
            }else if(cmd=="east"){
                temp = t;
                t = w;
                w = 7-temp;
            }else if(cmd=="west"){
                temp = w;
                w = t;
                t = 7-temp;
            }else if(cmd=="south"){
                temp = n;
                n = 7-t;
                t = temp;
            }
        }
        cout << t << endl;
    }
}