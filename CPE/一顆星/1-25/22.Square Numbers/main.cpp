#include<iostream>
#include<cmath>

using namespace std;
int main(){
    int h ,l;
    cin >> l >> h;
    while(h!=0 && l!=0){
        
        int count = 0;
        for(int i=l;i<=h;i++){
            if(sqrt(i)==(int)sqrt(i)){
                count ++;
            }
        }
        cout << count << endl;
        cin >> l >> h;
    }
}