#include<iostream>
using namespace std;

string weekday[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int dayinmonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};


string countday(int m , int d){
    int num = 0;
    if((m==4&&d==4) || (m==6&&d==6) || (m==8&&d==8) || (m==10&&d==10) || (m==12&&d==12)){
        return weekday[1];
    }

    for(int i=0;i<m-1;i++){
        num += dayinmonth[i];
    }
    num+=d;

    return weekday[(num+5)%7];

}


int main(){
    int no;
    cin >> no;

    for(int i=0;i<no;i++){
        int m,d;
        cin >> m >> d;
        cout << countday(m,d) << endl;
    }

}