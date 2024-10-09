//§d·¢¶v B123245005 
//2024/09/20 
//HW1.1 MagicSquare
#include  <iostream> // inclde basic iostreaming header
#include<iomanip>  // including io manipulate header

using namespace std; // using standard namespace



void checkRange(int &x, int &y, int R){  //this function check if we are out of the main operation board
	if(x<0){
		x = R-1; // if x is out of range, it should return into the original
	}
	if(y<0){
		y = R-1; // if y is out of range, it should return into the original
	}
}

int main(){
	int demoList[] = {1,3,5,7,9};
	for(int rangeIndex=0;rangeIndex<=4;rangeIndex++){
		int range = demoList[rangeIndex];
		int board[range][range] = {0}; // init the operating board  
		/* example
		0  0  0   y0 
		0  0  0   y1
	    0  0  0   y2
		x0 x1 x2
		end of example*/ 
		int index_x = (range-1)/2;//init current x axis position
		int index_y = 0;//init current y axis position
		int current = 1;//init the number the we're filling into the position
		
		
		for(int i=1;i<=range;i++){
			for(int j=1;j<=range;j++){
				board[index_y][index_x] = current;//fill in the current number into the specified position
				if(j!=range){ //If j is equal to range
					index_x--; //index x ant y should minus one 
					index_y--;
				}
				current++; //Increasing the filling number for one
				checkRange(index_x, index_y, range); // call the checkRange method, check if we're still in the main board(or overflowed)
			}
			index_y+=1; //On finishing the inner loop, y should increase one to make pointer go down a block
			checkRange(index_x, index_y, range); // checkRange again(though it should never overflowed here)
		} 
		
		
		for(int i=0;i<range;i++){ // interating the y axis
			for(int j=0;j<range;j++){ // interating the x axis  
				cout << setw(3) <<board[i][j] << " ";  // iostreaming the board with formatted
			}
			cout<<endl; //print \n
		}
		
		cout << endl << endl;
	}
}
