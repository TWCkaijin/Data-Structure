#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    for(int t=0;t<tc;t++){
        int price[36]= {0};
        for(int ch=0;ch<36;ch++){
            cin >> price[ch];
        }
        int cases ;
        cin >> cases;
        cout << "Case " << t+1 << ":" << endl;
        for(int i = 0;i<cases;i++){
            
            long long int num;
            cin >> num;

            vector <int> base_set;
            unsigned long long int minprice = -1;


            for(int base = 2;base<=36;base++){
                long long int numtemp = num;
                unsigned long long  sum = 0;
                while(numtemp>0){
                    sum += price[numtemp%base];
                    numtemp/=base;
                }

                if(sum<minprice){
                    base_set.clear();
                    base_set.push_back(base);
                    minprice = sum;
                }else if(sum==minprice){
                    base_set.push_back(base);
                }
            }
            cout <<"Cheapest base(s) for number "<<num<<": ";
            for(int cbase: base_set){
                if(cbase == base_set.back())cout << cbase;
                else cout << cbase << " ";
            }

            base_set.clear();
            cout << endl;
        }

        if(t!=tc-1)cout << endl;
    }
}