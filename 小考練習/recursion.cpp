#include<iostream>

using namespace std;

int AF(int m,int n){
	if (m==0){
		cout << "+1";
		return n+1;
	}else if(n==0){
		cout << endl;
		return AF(m-1,1);
	}else{
		cout << endl;
		return AF(m-1,AF(m,n-1));
	}
}


int main(){
	int x = AF(2,2);
	cout << endl << x<< endl;
} 
