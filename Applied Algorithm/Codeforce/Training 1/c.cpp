#include<iostream>
using namespace std;

const int N = 1000000007;

int main(){
    unsigned long long a,b;  
    cin >> a >> b;
    a %= N;
    b %= N;
    cout << (a+b) % N;
    return 0;
}