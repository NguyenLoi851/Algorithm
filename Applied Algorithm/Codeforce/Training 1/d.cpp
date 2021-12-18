#include <iostream>
using namespace std;

const int N=1000000007;

unsigned long long function(unsigned long long a, unsigned long long b){
	if(b==0) return 1;
    if(b==1){
		return a%N;
	}else{
		
        if(b % 2 == 0){
            unsigned long long temp = function(a, b/2)%N;
            return temp * temp %N;
        }else{
            unsigned long long temp = function(a, (b-1)/2)%N;
            return (((temp * temp)%N)* (a%N))%N;
		}
	}
}

int main(){
    unsigned long long a, b;
    cin >> a >> b;
    cout << function(a,b); 
    return 0;
}