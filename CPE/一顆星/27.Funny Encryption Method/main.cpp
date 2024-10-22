#include <bits/stdc++.h>
using namespace std;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int i, j, k;
	int t, n;
	
	cin >> t;
	
	for (i=0;i<t;i++) {
		cin >> n;
		
		int b1 = 0, b2 = 0;
		
		for (j=n;j>0;j=j/2)
			b1 = b1 + j % 2;
				
		string x = to_string(n);
		
		int hex[10]={0,1,1,2,1,2,2,3,1,2};
		
		for(j=0;j<x.size();j++)
			b2 = b2 + hex[x[j]-'0'];
		
		cout << b1 << " " << b2 << endl;
	}

	return 0;
}