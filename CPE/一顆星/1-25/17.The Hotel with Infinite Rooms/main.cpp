#include<iostream>


using namespace std;

int main()
{
    long int n;
    unsigned long long int day;
    while(cin >> n >> day){
        long long int sum = 0;

        while(sum<day){
            sum += n;
            n++;
        }
        cout << n-1 << endl;
    }
}