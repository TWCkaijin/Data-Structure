#include<iostream>


using namespace std;

int main(){

    int cases;
    cin >> cases;
    for(int c=0;c<cases;c++){
        int days, parties;
        cin >> days >> parties;
        int hartal[parties] = {0};

        for(int p=0;p<parties;p++){
            cin >> hartal[p];
        }

        int count = 0;

        for(int d=1;d<=days;d++){
            for(int p=0;p<parties;p++){
                if(d%hartal[p]==0 && d%7!=6 && d%7!=0){
                    count ++;
                    break;
                }
            }
        }

        cout << count << endl;
    }
}