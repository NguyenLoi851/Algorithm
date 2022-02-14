#include <bits/stdc++.h>
using namespace std;

int N;
int res=0;

int main(){
	cin>>N;
	N=1000-N;

	res+=N/500;
	N=N-(N/500)*500;

	res+=N/100;
	N=N-(N/100)*100;

	res+=N/50;
	N=N-(N/50)*50;

	res+=N/10;
	N=N-(N/10)*10;

	res+=N/5;
	N=N-(N/5)*5;

	res+=N;

	cout<<res;
	return 0;
}

