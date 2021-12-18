#include "iostream"
using namespace std;

const int N=1000000007;

int main(){
    int n;
    cin >> n;
    unsigned long long temp, res = 0;
    for(int i=0;i<n;i++){
        cin >> temp;
        temp %= N;
        res += temp;
        res%=N;
    }
    cout<< res; 
    return 0;
}