#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i<N; i++){
        char a, b;
        int M;
        cin >> a >> b >> M;
        vector<long long int>num;
        bool negative = false;
        for (int j = 0; j<M; j++){
            for (int k = 0; k<M; k++){
                long long int tmp;
                cin >> tmp;
                num.push_back(tmp);
                if (tmp < 0) negative = true;
            }
        }
        if (!negative){
            vector<long long int>tmp = num;
            reverse(tmp.begin(), tmp.end());
            if (tmp == num) cout << "Test #" << i+1 << ": Symmetric.\n";
            else cout << "Test #" << i+1 << ": Non-symmetric.\n";
        }
        else cout << "Test #" << i+1 << ": Non-symmetric.\n";
    }
}