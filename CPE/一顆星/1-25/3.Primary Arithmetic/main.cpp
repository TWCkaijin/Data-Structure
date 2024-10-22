#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    string x,y;
    while(cin>>x>>y , !(x=="0"&&y=="0")){

        reverse(x.begin(),x.end());
        reverse(y.begin(),y.end());

        int maxsize = x.size()<y.size()?y.size():x.size();  
        int count=0;
        int carry =0;
        for(int i=0;i<maxsize;i++){
            int x_digit = i<x.size()?x[i]-'0':0;
            int y_digit = i<y.size()?y[i]-'0':0;

            if(x_digit + y_digit + carry >=10){
                count ++;
                carry = 1;
                
            }else{
                carry=0;
            }
        }

        if(count==0){
            cout<<"No carry operation."<<endl;
        }else if(count==1){
            cout<<"1 carry operation."<<endl;
        }else{
            cout<<count<<" carry operations."<<endl;
        }
        x.clear();
        y.clear();
        carry=0;
        count=0;
    }
}