#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    int N;
    int no=0;
    while(cin >>N ){
        no++;
        vector <int> numset;
        vector <int> sumset;
        for(int i=0;i<N;i++){
            int num;
            cin >> num;
            numset.push_back(num);
        }

        bool cond = true;

        for(int i=0;i<N;i++){
            for(int j=i;j<N;j++){
                if(find(sumset.begin(),sumset.end(),numset[i]+numset[j])!=sumset.end()){
                    cond = false;
                    break;
                }else{
                    sumset.push_back(numset[i]+numset[j]);
                }
            }
            if(!cond) break;
        }
        if(cond){
            cout << "Case #" << no << ": It is a B2-Sequence." << endl;
            cout << endl;
        }else{
            cout << "Case #" << no << ": It is not a B2-Sequence." << endl<<endl;
        }

    }

}