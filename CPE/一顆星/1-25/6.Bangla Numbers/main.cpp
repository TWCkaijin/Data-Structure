#include<iostream>
#include<string>
using namespace std;

string split(unsigned long long int  n, string &result){
    if(n>=10000000){
        split(n/10000000, result);
        n %= 10000000;
        result += "kuti ";
    }
    if(n>=100000){
        split(n/100000, result);
        n %= 100000;
        result += "lakh ";
    }

    if(n>=1000){
        split(n/1000, result);
        n %= 1000;
        result += "hajar ";
    }

    if(n>=100){
        split(n/100, result);
        n %= 100;
        result += "shata ";
    }

    if(n>0){
        result += to_string(n) + " ";
    }

    return result;
}


int main(){
    string input;
    int times = 0;
    while(cin >> input){
        cout << ++times << ". ";
        if(input=="0"){
            cout << "0" << endl << endl;
            continue;
        }
        long double n = stold(input);
        unsigned long long int interger = stoll(input);
        long double decimal = n - interger;

        string res="";
        res = split(interger, res);
        if (input.find('.') == string::npos){
            cout << res << endl;
        } else if(decimal==0.0){
            cout << res << ".0" << endl;
        }else {
            string decimal_str = to_string(decimal).substr(1);
            cout << res << decimal_str << endl;
        }

        cout << endl;
    }
    return 0;
}