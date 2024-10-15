#include<iostream>
using namespace std;

long int step(int y){
    if(y==0)return 0;
    return y + step(y-1);
}

int main(){
    long int cases,x1,y1,x2,y2;
    cin >> cases;
    for(int c=0;c<cases;c++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << "Case " << c+1 << ": " <<x2 + step(x2+y2) -x1 -step(x1+y1) << endl;
    }
}