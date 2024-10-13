#include <iostream>
#include <iomanip>
#include <chrono>
#include <windows.h>
#include <psapi.h>
using namespace std;


typedef struct Node{
    int x;
    int y;
    int k;
    int direction;
    Node *last;
    Node(int a, int b, int index,int d, Node *n): x(a), y(b), k(index),direction(d), last(n){}
} Node;

int directions[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

int moving(int **board , Node *current,int direction ,int n){
    int x = current->x;
    int y = current->y;
    int tempd = direction==-1?0:direction+1;

    for(int i=tempd; i<8; i++){
        int tempx = x+directions[i][0];
        int tempy = y+directions[i][1];
        if(tempx>=0 && tempx<n && tempy>=0 && tempy<n && board[tempx][tempy]==0){
            return i;
        }
    }
    return -1;
}

void printBoard(int **board, int n){
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
        bool solution = true;
        int **board = new int*[n];
        for(int i=0;i<n;i++){
            board[i] = new int[n];
            for(int j=0;j<n;j++){
                board[i][j] = 0;
            }
        }
        
        Node *head = new Node(0,0,1,-1,nullptr); // x , y , k , direction , next
        board[0][0] = 1;

        while(head->k<n*n){
            
            //cout << "k=" << head->k+1 << endl;
            int destination = moving(board,head,head->direction,n);
            //cout << "destination: " << destination << endl;
            if(destination==-1 ){

                if(head->k==1){
                    cout << "No solution" << endl;
                    solution = false;
                    break;
                }
                board[head->x][head->y] = 0;
                Node *temp = head;
                head = head->last;
                delete temp;
            }else{
                head->direction = destination;

                Node *temp = new Node(head->x + directions[head->direction][0],
                                    head->y + directions[head->direction][1],
                                    head->k+1,
                                    -1,
                                    head); 
                head = temp;
                board[head->x][head->y] = head->k;
            }
        }
        if(solution){
            printBoard(board,n);
        }
        cout << endl;
    }
}
