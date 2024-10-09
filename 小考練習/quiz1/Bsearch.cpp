#include<iostream>

using namespace std;


int Bs(int a[],int R,int L, int t){
	int index = (R-L)%2==0 ? (R-L)/2+L : (R-L-1)/2+L;
	cout << "current index:" << index << endl;
	
	if(a[index]==t)return index;
	if(a[R]==t)return R;
	if(a[L]==t)return L;
	
	
	if (a[index] > t){
		Bs(a,index,L,t);
	}else{
		Bs(a,R,index,t);
	}
	
	
}



int main(){
	int arr[20] = {1,2,3,4,5,6,7,8,9,10,11,11,13,14,15,16,17,18,19,20};
	int target = 11;
	cout << Bs(arr, 19, 0, target) << endl;
	
} 
