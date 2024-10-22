#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
using namespace std;

int m;


int main(){
    int n;
    while(cin >> n>>m, n!=0 && m!=0){
        vector<int> numset;
        for(int c=0;c<n;c++){
            int input;
            cin>>input;
            numset.push_back(input);
        }

        random_device rd;
        mt19937 g(rd());
        shuffle(numset.begin(), numset.end(), g);

        sort(numset.begin(),numset.end(),[](int a ,int b){
            int ta = a%m , tb = b%m;
            if(ta!=tb ){
                return ta < tb;
            }else{
                if(a%2 == b%2 && a%2==1){
                    return a>b;
                }else if(a%2 == b%2 && a%2==0){
                    return a<b;
                }else{
                    return a%2>b%2;
                }
            }
        });
        cout << n << " " << m << endl;
        for(int i:numset){
            cout << i << endl;
        }
    }
    cout << "0 0";
}
