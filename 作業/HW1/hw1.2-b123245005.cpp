//Author: §d·¢¶v B123245005 
//Date: 2024/09/20 
//Purpose: HW1.1 MagicSquare
#include<iostream> // using basic in out streaming header file
#include<vector>
using namespace std; // using standard namespace definition
const int MAX_INDEX = 200; // set the max index of array to be 200;

void arrCheck(int arr[]); // preload the method for early call
void arrPrint(int arr[]); // preload the mothod for early call


void arrMulti(int times, int arr[]){
	for(int i=MAX_INDEX-1;i>=0;i--){ // iterating the list for operation
		arr[i] *= times; //timming all the element with 'times"
	}
	arrCheck(arr); // call arrCheck function to check if each element has reach or over its limit of 10
	arrPrint(arr); // print out each element in the array
}

void arrCheck(int arr[]){ // the check if any element has reach or over its limit of 10
	for(int i=MAX_INDEX-1;i>1;i--){ // interating the array for operation
		if(arr[i]>=10){  // if its elemet is more than 1 0
			arr[i-1] += arr[i]/10; // the formal elememt should increase 
			arr[i] %= 10; // and it should decade to its remainder to 10
		}
	}
}


void arrPrint(int arr[]){ // this method will print out all the element from the array
	bool flag = false; //setup the a flag the show when the numbers begin 
	for(int i=0;i<MAX_INDEX;i++){
		if(!flag && arr[i]!=0){
		flag=true; // set flag to true if it is  
		}
		if(flag){
		cout << arr[i]; // start printing from when the flag became true
		}
	}
	cout << endl;
} 


int main(){
	
	vector<int> demoList;
	int demoindex=0;
	cout << "N:";  //input prompt
	while(true){
		int temp;
		cin >> temp;
		demoList.push_back(temp);
		demoindex++;
		if(temp==0)break; //if zero , end reading the input
	}
	
	for(int i=0;i<demoindex-1;i++){
		int input = demoList[i];
		int num[MAX_INDEX] = {0}; // setup a full empty array with max index
		for(int i=0; i<MAX_INDEX; i++){ 
			num[i] = 0; // setup all to zero to prevent errors or unexpect probloms
		}
		
		if(input>=1){  //exception handling for 1 factorial 
			num[MAX_INDEX-1] = 1;
			cout << "1!=";
			arrPrint(num);
		}
		
		
		for(int n=2;n<=input;n++){
			cout << n << "!=" ;
			arrMulti(n,num);
		}
		cout << endl;
	}
	
	
	
	
}
