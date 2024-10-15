#include<iostream>


using namespace std;

int main(){
    int r ,c;
    while(cin >> r>>c, r!=0 && c!=0){
        int **arr = new int*[r];
        for(int i = 0; i < r; i++){
            arr[i] = new int[c];
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin >> arr[i][j];
            }
        }

        
    }
}