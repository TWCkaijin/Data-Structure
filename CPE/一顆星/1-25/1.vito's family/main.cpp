#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int cases = 0;
    cin >> cases;
    
    for(int i=0;i<cases;i++){
        int len=0;
        cin >> len;
        int arr[len] = {0};
        for(int j=0;j<len;j++){
            cin >> arr[j];
        }   
        sort(arr,arr+len);
        int midvalue = len%2==0? (arr[len/2-1]+arr[len/2])/2: arr[len/2] ;
        int sum=0;
        for(int j=0;j<len;j++){
            sum += abs(arr[j] - midvalue);
        }
        cout << sum << endl;
    }
    
}