#include<iostream>


using namespace std;


void per(char a[], int k, int m){
	if(k==m){
		for(int i=0;i<=m;i++){
			cout << a[i];
		}
		cout<<endl;
	}else{
		for(int i= k;i<=m;i++){
			swap(a[i],a[k]);
			per(a,k+1,m);
			swap(a[i],a[k]);
		}
	}
}


int main(){
	char arr[3] = {'A','B','C'};
	per(arr,0,2);
	
} 
