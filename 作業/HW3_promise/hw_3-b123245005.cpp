#include <iostream>
#include <iomanip>
#include <chrono>
#include <windows.h>
#include <psapi.h>
using namespace std;


typedef struct Node{
    int x;  // recording the x axis position 
    int y;  // recording the y axis position
    int k;  // rocording the current step
    int direction; // recording the current directionto move
    Node *last; // recording the last node // 紀錄上一個stack node 節點
    Node(int a, int b, int index,int d, Node *n): x(a), y(b), k(index),direction(d), last(n){} //constructor
} Node; // 直接定義型別

int directions[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}}; // direction set

int moving(int **board , Node *current,int direction ,int n){
    int x = current->x;  // clone the current x position
    int y = current->y;  // clone the current y position
    int tempd = direction==-1?0:direction+1; // if its the first time to move, then start from 0, else start from the next direction

    for(int i=tempd; i<8; i++){
        int tempx = x+directions[i][0]; // make up the temp var for x position after moving
        int tempy = y+directions[i][1]; // make up the temp var for y position after moving
        if(tempx>=0 && tempx<n && tempy>=0 && tempy<n && board[tempx][tempy]==0){ // if the position is valid
            return i;  // return the direction to move
        }
    }
    return -1; // if no direction to move, return -1
}

void printBoard(int **board, int n){ // print the board with specific format
    for(int i=0;i<n;i++){  
        for(int j=0;j<n;j++){
            cout << setw(3) << board[i][j] << " "; 
        }
        cout << endl;
    }
}

int main(){
    for(int n=1;n<=6;n++){
        cout << "n=" << n <<": "<< endl;
        bool solution = true;  // if there is a solution
        int **board = new int*[n]; //dynamic allocate the board

        for(int i=0;i<n;i++){
            board[i] = new int[n];
            for(int j=0;j<n;j++){
                board[i][j] = 0;  // initialize the board
            }
        }
        
        Node *head = new Node(0,0,1,-1,nullptr); // x , y , k , direction , next
        board[0][0] = 1;  // start from 1 at position (0,0)

        while(head->k<n*n){  // while the step is not enough
            
            int destination = moving(board,head,head->direction,n); // get the direction to move
            if(destination==-1 ){  // if no direction to move
                if(head->k==1){  // if the step is 1, then no solution
                    cout << "No solution" << endl;
                    solution = false;
                    break;
                }
                board[head->x][head->y] = 0; // reset the position
                Node *temp = head; // clone the current node
                head = head->last; // move to the last node
                delete temp;    // delete the current node
            }else{
                head->direction = destination;  // set the direction to move

                Node *temp = new Node(head->x + directions[head->direction][0], 
                                    head->y + directions[head->direction][1], 
                                    head->k+1,
                                    -1,
                                    head); // create a new node
                head = temp; // move to the new node
                board[head->x][head->y] = head->k; // set the position on the board to the current step's number
            }
        }
        if(solution){
            printBoard(board,n);  // nothing special , just print the board
        }
        cout << endl;
    }
}
