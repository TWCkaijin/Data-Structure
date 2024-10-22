#include<iostream>

using namespace std;

int main(){
    int cases;
    cin>>cases;
    for(int i=0;i<cases;i++){
        int x,y;
        cin >> x >> y;
        int sum = 0;
        int high = max(x,y), low = min(x,y);
        for(int j=low;j<=high;j++){
            if(j%2!=0){
                sum += j;
            }
        }
        cout << "Case " << i+1 << ": " << sum << endl;
    }
}