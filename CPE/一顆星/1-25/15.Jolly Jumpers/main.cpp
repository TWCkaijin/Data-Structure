#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int input;
        vector<int> num;
        vector<int> diff;
        for(int i=0;i<n;i++){
            cin >> input;
            num.push_back(input);
        }

        for(int i=0;i<n-1;i++){
            diff.push_back(abs(num[i]-num[i+1]));
        }

        sort(diff.begin(),diff.end());
        bool flag = true;
        for(int i=1;i<n;i++){
            if(diff[i-1]!=i){
                cout << "Not jolly" << endl;
                flag = false;
                break;
            }
        }
        if(flag)cout << "Jolly" << endl;

    }

}