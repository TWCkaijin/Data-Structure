#include<iostream>

using namespace std;

int dindex(char t, int c_d=-1){
    if(c_d==-1){
        if(t=='N')return 0;
        if(t=='W')return 1;
        if(t=='S')return 2;
        if(t=='E')return 3;
    }else{
        if(t=='R')return (c_d+3)%4;
        if(t=='L')return (c_d+1)%4;
    }
}


int main(){
    int direction[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
    char dest[] = {'N','W','S','E'};
    int MAX_X , MAX_Y;
    cin >> MAX_X >> MAX_Y;
    int board[MAX_X][MAX_Y] = {0};
    int x,y;
    char tempd;
    int d;
    while(cin >> x >> y >> tempd){ 
        d = dindex(tempd);
        string cmds;
        bool isout = false;
        int tempx=0, tempy=0;
        getline(cin,cmds);
        cmds.clear();
        getline(cin,cmds);
        for(char cmd:cmds){
            
            if(cmd=='\n')break;
            if(cmd=='F'){

                tempx = x+direction[d][0], tempy = y+direction[d][1];
                if(tempx>=0 && tempx<=MAX_X && tempy>=0 && tempy<=MAX_Y){
                    x = tempx;
                    y = tempy;
                }else if(board[x][y]==-1){
                    continue;
                }else {
                    board[x][y]=-1;
                    isout = true;
                    break;
                }
            }else{
                d = dindex(cmd,d);
            }
        }
        if(!isout)cout << x << " " << y << " " << dest[d] << endl;
        else cout << x << " " << y << " " << dest[d] <<" LOST"<< endl;
    }
    
}