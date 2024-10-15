#include<iostream>
#include<vector>

using namespace std;

vector<long int> &fib(long int n){
    if(n == 1){
        vector<long int> *fibs = new vector<long int>();
        fibs->push_back(1);
        return *fibs;
    }else{
        vector<long int> *fibs = new vector<long int>();
        fibs->push_back(1);
        fibs->push_back(2);
        int i = 2;
        while(fibs->back() <= n){
            fibs->push_back(fibs->at(i-1) + fibs->at(i-2));
            i++;
        }
        if(fibs->back() > n){
            fibs->pop_back();
        }
        return *fibs;
    }
}

int main(){
    int cases = 0;
    cin >> cases;

    for(int i=0;i<cases;i++){
        long int n = 0;
        cin >> n;
        cout << n << " = ";
        vector<long int> fibs = fib(n);

        for(int j=fibs.size()-1;j>=0;j--){
            if(n>=fibs[j]){
                cout << "1";
                n-=fibs[j];
            }else{
                cout << "0";
            }
        }

        cout << " (fib)" << endl;
    }
}