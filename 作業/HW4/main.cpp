#include<iostream>
#include<iomanip>
using namespace std;

int direction[8][2] = {{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};


bool isValid(int **board, int x, int y, int n){
    return (x>=0 && x<n && y>=0 && y<n && board[y][x]==0);
}


bool route(int **board, int x, int y, int k, int n ,int d){ 
            // board, x pos, y pos, current depth k, max depth n, current direction d; 
    if(k > n*n){
        return true;
    }
    if(d>=8){
        return false;
    }
    //cout << k << " ";
    //next move
    int nx = x + direction[d][0];
    int ny = y + direction[d][1];
    if(isValid(board,nx,ny,n)){
        board[ny][nx] = k;
        if(route(board,nx,ny,k+1,n,0)){ //next node
            return true;
        }
        board[ny][nx] = 0;
        
    }
    return route(board,x,y,k,n,d+1);  // diff direction 
}


void printBoard(int **board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << setw(3) << board[i][j];
        }
        cout << endl;
    }
}


int main(){
    for(int n=1;n<=6;n++){
        cout << n << "." << endl;
        int **board = new int*[n];
        for(int i=0;i<n;i++){
            board[i] = new int[n];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i][j] = 0;
            }
        }

        board[0][0] = 1;
        if(route(board,0,0,2,n,0)){
            printBoard(board,n);
        }else{
            cout << "No Solution" << endl;
        }
        cout<<endl<<endl;


        for(int i=0;i<n;i++){
            delete []board[i];
        }
        delete []board;
    }
}